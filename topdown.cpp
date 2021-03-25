#include<iostream>
#include<string>

using namespace std;

#define ROW 4
#define COL 4

void print_path(char mat[ROW][COL], int i, int j, string path) {
  if(i==ROW-1) {
    cout<<path<<mat[i][j]<<endl;
    return;
  }

  // move row-wise down-left
  if(i+1<ROW) {
    // 
    if(j-1>=0)	
      print_path(mat, i+1, j-1,path+mat[i][j]);
    if(j-2>=0)
	    print_path(mat,i+1, j-2,path+mat[i][j]);

    // move down
    //print_path(mat, i+1, j,path+mat[i][j]);

    // move down-right
    if(j+1<COL)
      print_path(mat,i+1, j+1,path+mat[i][j]);
    if(j+2<COL)
	    print_path(mat,i+1, j+2,path+mat[i][j]);
  }
}


int main() {
  char mat[ROW][COL] = {{'1','2','3','4'},{'5','6','7','8'},{'9','a','b','c'},{'d','e','f','g'}};
  
  print_path(mat, 0, 0, "");
  print_path(mat, 0, 1, "");
  print_path(mat, 0, 2, "");
  print_path(mat, 0, 3, "");

 /* for(int i=0;i<ROW; i++){
    for(int j=0; j<COL; j++) {
      print_path(mat, i, j, "");
    }
  }*/
  return 0;
}
