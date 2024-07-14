#include <iostream>
using namespace std;

bool endGame = false;
char player = 'X';
int position = 0; //para que entre al while si o si
int num_plays = 0;
char table[3][3] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'},
};

int rows = sizeof(table) / sizeof(table[0]);
int cols = sizeof(table[0]) / sizeof(table[0][0]);

void printTable(int position, char player, char (*table)[3]){ //posicion en el tablero a colocar
  int counter = 0;

  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      counter = counter + 1;
      if(counter == position) {
        table[i][j] = player;
      }

      cout << table[i][j] << " ";
    }
    cout << endl;
  }
}

bool verifyPosition(int position, char (*table)[3]){
  char value;
  int counter = 0;

  if(position <= 0 || position > 9) {
    cout << "Posicion fuera de rango" << endl;
    return false;
  }

  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      counter = counter + 1;

      if(counter == position && table[i][j] != '-') { //ese espacio ya esta ocupado
        cout << "Espacio ya ocupado" << endl;
        return false;
      }
    }
  }

  return true;
}

bool checkWin(char (*table)[3]) {

  // Check rows
  for (int i = 0; i < 3; i++) {
    if (table[i][0] == table[i][1] && table[i][1] == table[i][2] && table[i][0] != '-') {
        return true;
    }
  }

  // Check columns
  for (int i = 0; i < 3; i++) {
    if (table[0][i] == table[1][i] && table[1][i] == table[2][i] && table[0][i] != '-') {
        return true;
    }
  }

  // Check diagonals
  if (table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[0][0] != '-') {
      return true;
  }

  if (table[0][2] == table[1][1] && table[1][1] == table[2][0] && table[0][2] != '-') {
      return true;
  }

  return false;
};

int main(){
  cout << endl;
  while (endGame == false){

    cout << "Juegan: " << player << endl;
    do {
      cout << "Ingresa la posicion del tablero [1-9]: ";
      cin >> position;
    } while (!verifyPosition(position, table));

    num_plays = num_plays + 1;
    printTable(position, player, table);

    if (checkWin(table)) {
      cout << "¡El jugador '" << player << "' gana!" << endl;
      endGame = true;
    } else {
      // Cambio de jugador
      player = (player == 'X') ? 'O' : 'X';
    }

    if(num_plays == 9) {
      endGame = true;
      cout << "Empate" << endl;
    }
  }

  cout << "Juego terminado" << endl;
  return 0;
}