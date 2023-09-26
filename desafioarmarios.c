#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  unsigned char armarios = 0;
  int x;
  int mask = 1;
  int desloc;
  int verifica;
  srand(time(NULL));
  
  while(1){
    puts("\n1. Ocupar armário");
    puts("2. Liberar armário");
    puts("3. Sair");
    scanf("%d", &x);
  if(x == 3)
    break;

  if(x == 1){
     while(1) {
     mask = 1;
     desloc = rand() % 8;
     verifica = armarios >> desloc;
     
     if(verifica % 2 == 0) {
       mask = mask<<desloc;
       armarios = armarios ^ mask;
       break;
     } else {
    continue;
     }
     } 
     printf("Estado dos armários:\n");
        for (int i = 0; i < 8; i++) {
        if (armarios & (1 << i)) {
            printf("Armário %d: Ocupado\n", i + 1);
        } else {
            printf("Armário %d: Livre\n", i + 1);
}
} 
}
  if(x == 2){
      if(armarios == 0){
        puts("Nenhum armário está ocupado\n");
        continue;
      }
      puts("Qual armário deseja liberar?\n");
      scanf("%d", &desloc);
      verifica = armarios>> (desloc-1);
      if(verifica % 2 == 1) {
        mask = 1;
        armarios &= ~(mask<<(desloc-1));
      } else {
        puts("Esse armário já esta livre\n");
      }
     printf("Estado dos armários:\n");
    for (int i = 0; i < 8; i++) {
        if (armarios & (1 << i)) {
            printf("Armário %d: Ocupado\n", i + 1);
        } else {
            printf("Armário %d: Livre\n", i + 1);
        }
    }
    }
  if(armarios == 255)
    puts("Todos os armários estão ocupados. Libere algum.\n");
  }
  return 0;
}