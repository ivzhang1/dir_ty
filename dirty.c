#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void list_files(){
  DIR * stream = opendir(".");
  

  
  closedir(stream);

  
}

void list_dir(){
  DIR * stream = opendir(".");
  
  closedir(stream);

  
}


void total_sizes(){
  DIR * stream = opendir(".");
  struct dirent *entry = readdir(stream);
  printf("%d SIZE\n", stat(entry
  
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


int main(){
  list_files();
  return 0;
}
