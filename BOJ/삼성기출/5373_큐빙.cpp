#include <iostream>
#include <vector>
using namespace std;

void clockwise(vector<vector<char> > &arr){
  int n=3;
  char temp=arr[0][0];
  arr[0][0]=arr[2][0];
  arr[2][0]=arr[2][2];
  arr[2][2]=arr[0][2];
  arr[0][2]=temp;

  temp=arr[0][1];
  arr[0][1]=arr[1][0];
  arr[1][0]=arr[2][1];
  arr[2][1]=arr[1][2];
  arr[1][2]=temp;
}

void R(vector<vector<vector<char> > > &arr){
  //나머지 면 돌리기 : 0 > 3 > 5 > 1
  vector<vector<char> > temp = arr[0];
  // 그 면들의 색을 올바르게 변경
  for(int i=0; i<3; i++){
    arr[0][i][2] = arr[1][i][2];
    arr[1][i][2] = arr[5][i][2];
    arr[5][i][2] = arr[3][i][2];
    arr[3][i][2] = temp[i][2];
  }
  clockwise(arr[2]); // 2번 면은 시계 방향으로 돌린다
}


// 왼쪽 면을 시계 방향으로 돌리는 함수 L
void L(vector<vector<vector<char> > >  &arr){
  vector<vector<char> > temp = arr[0];
  // 0 > 1 > 5 > 3
  for(int i=0; i<3; i++){
    arr[0][i][0]=arr[3][i][0];
    arr[3][i][0]=arr[5][i][0];
    arr[5][i][0]=arr[1][i][0];
    arr[1][i][0]=temp[i][0];
  }
  clockwise(arr[4]);
}


// 앞면 돌리기
void F(vector<vector<vector<char> > > &arr){
  // 오른쪽으로 회전
  vector<vector<char> > temp=arr[1];
  arr[1]=arr[4];
  arr[4]=arr[3];
  arr[3]=arr[2];
  arr[2]=temp;

  // 1,2,3,4면 좌표 맞추기
  clockwise(arr[1]); clockwise(arr[1]); clockwise(arr[1]);
  clockwise(arr[2]); clockwise(arr[2]); clockwise(arr[2]);
  clockwise(arr[3]); clockwise(arr[3]); clockwise(arr[3]);
  clockwise(arr[4]); clockwise(arr[4]); clockwise(arr[4]);

  // 0번면은 반시계, 5번면은 시계
  clockwise(arr[0]); clockwise(arr[0]); clockwise(arr[0]);
  clockwise(arr[5]);
}


// 오른쪽으로 굴리기
void U(vector<vector<vector<char> > > &arr){
  vector<vector<char> >  temp=arr[0];
  arr[0]=arr[4];
  arr[4]=arr[5];
  arr[5]=arr[2];
  arr[2]=temp;

  //4,5번면 180도
  clockwise(arr[4]); clockwise(arr[4]);
  clockwise(arr[5]); clockwise(arr[5]);

  // 1번면 시계, 3번면 반시계
  clockwise(arr[1]);
  clockwise(arr[3]); clockwise(arr[3]); clockwise(arr[3]);
}

// 좌표 0,0
int main(){
  int t;
  cin >> t;
  while(t--){
    int m;
    cin >> m;
    vector<vector<vector<char> > > arr;
    arr.push_back(vector<vector<char> > (3, vector<char>(3,'w')));
    arr.push_back(vector<vector<char> > (3, vector<char>(3,'r')));
    arr.push_back(vector<vector<char> > (3, vector<char>(3,'b')));
    arr.push_back(vector<vector<char> > (3, vector<char>(3,'o')));
    arr.push_back(vector<vector<char> > (3, vector<char>(3,'g')));
    arr.push_back(vector<vector<char> > (3, vector<char>(3,'y')));

    while(m--){
      string s;
      cin >> s;
      int k=1;
      if(s[1]=='-') k=3;

      if(s[0]=='U'){ // 윗면 돌리기
        U(arr); // 굴리고
        for(int i=0; i<k; i++) R(arr); // 오른쪽 면 돌리고
        //k=1시계 방향 3=반시계방향
        for(int i=0; i<3; i++) U(arr); //세번 굴린다
      }
      else if(s[0]=='D'){ // 아랫면 돌리기
        U(arr); // 굴리고
        for(int i=0; i<k; i++) L(arr); // 왼쪽 면
        for(int i=0; i<3; i++) U(arr);
      }

      else if(s[0]=='F'){ // 앞면
        F(arr);
        for(int i=0; i<k; i++) R(arr);
        for(int i=0; i<3; i++) F(arr);
      }
      else if(s[0]=='B'){ // 뒷면
        F(arr);
        for(int i=0; i<k; i++) L(arr);
        for(int i=0; i<3; i++) F(arr);
      }

      else if(s[0]=='L'){
        for(int i=0; i<k; i++) L(arr);
      }
      else if(s[0]=='R'){
        for(int i=0; i<k; i++) R(arr);
      }
    }

    for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
        cout << arr[0][i][j];
      }
      cout << '\n';
    }
  }



  return 0;
}
