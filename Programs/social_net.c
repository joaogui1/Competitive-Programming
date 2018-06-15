fread
#include <stdio.h>
#include <stdlib.h>

typedef struct myprofile Profile;

struct myprofile{
  char name[25];
  char username[16];
  Profile*  bff;
};

void createProfile(Profile **pnet){
  //static, é inicializada só uma vez
  static int network_size = 0;

  ++network_size;
  *pnet = realloc(*pnet, sizeof(Profile)*network_size);

  int pos = network_size - 1;

  printf("username: ");
  fgets((*pnet)[pos].username);

  printf("name: ");

}

void destroyNetwork(Profile *pnet){
  free(pnet);
}

int main(){
  Profile* net = NULL;
  createProfile(&net);


}
