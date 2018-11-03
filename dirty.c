#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

void list_files(char *dir){
  DIR * stream = opendir(dir);
  if (errno) {
    printf("%s\n", dir); 
    printf("%s\n", strerror(errno));
    return;
  }

  
  closedir(stream);

  
}

void list_dir(){
  DIR * stream = opendir(".");
  
  closedir(stream);

  
}


void total_sizes(){
  DIR * stream = opendir(".");
  struct dirent *entry = readdir(stream);
  //printf("%d SIZE\n", stat(entry));
  
  closedir(stream);

  
}

void total_sizes_recursive(){
  DIR * stream = opendir(".");

  
  

  
  closedir(stream);

  
}


void all_files_recursive(){
  DIR * stream = opendir(".");
  

  
  closedir(stream);

  
}


int main(int argc, char *argv[]){

  char dir[256];
  printf("Enter a directory name: ");
  fgets(dir, 256, stdin);

  
 
  while(dir[0] == '\n'){
    printf("Enter a directory name: ");
    fgets(dir, 256, stdin);
    //printf("%s\n", dir);
   }

  dir[strlen(dir)-1] = '\0';

  
  list_files(dir);
  return 0;
}
