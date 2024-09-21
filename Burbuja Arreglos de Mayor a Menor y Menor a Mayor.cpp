//Mayor a Menor
void mayorArreglo(){
  int aux;
  for (int i = 0; i < 7; i++){
      for (int j = 0; j < 7-1; j++){
        if (arreglo [j] < arreglo [j+1] ){ //Para ser ma especiifico solo se cambia el signo de menor - mayor en el if
            aux = arreglo [j+1] ;
            arreglo [j+1] = arreglo [j];
            arreglo [j] = aux;

      }
    }
  }
}
// Menor a Mayor
void menorArreglos(){
  int aux;
  for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 7 - 1; j++) {
          if (arreglo[j] > arreglo[j + 1]) { 
              aux = arreglo[j + 1];
              arreglo[j + 1] = arreglo[j];
              arreglo[j] = aux;
          }
      }
  }
