#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

void list_files(char *dir){
  DIR * stream = opendir(dir);
  struct dirent *entry;

  printf("Files:\n"); 

  entry = readdir(stream);
  while(entry){
    if(entry->d_type != DT_DIR){
      printf("\t%s\n", entry->d_name);
    }
    entry = readdir(stream);
  }
  
  closedir(stream);
}

void list_dir(char *dir){
  DIR * stream = opendir(dir);

  struct dirent *entry;

  printf("Directories:\n"); 

  entry = readdir(stream);
  while(entry){
    if(entry->d_type == DT_DIR){
      printf("\t%s\n", entry->d_name);
    }
    entry = readdir(stream);
  }
  
  closedir(stream);  
}

void list_both(char *dir){
  list_files(dir);
  list_dir(dir);

}

void total_size(char*dir){
  size_t size = 0;
  
  DIR * stream = opendir(dir);
  struct dirent *entry = readdir(stream);
  struct stat *file = malloc(sizeof(struct stat));
  
  while(entry){
    stat(entry->d_name, file);
    size += file->st_size;
    entry = readdir(stream);
  }
  

  printf("Size of all files: %ld Bytes\n", size); 
  printf("Size of all files: %ld kb\n",size / 1024);
  printf("Size of all files: %ld mb\n", ( size / (1024) ) / 1024);
  
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
  DIR * stream = opendir(dir);
  if(errno){
    printf("%s\n", strerror(errno));
    return 0;
  }
  printf("Statistics for directory: %s\n", dir);
  total_size(dir);
  list_both(dir);
  return 0;
}
