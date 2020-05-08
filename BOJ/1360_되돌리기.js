var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().trim();

var N;
    a = new Array();

// main
var line = input.split('\n');
N = line[0];

for(var i=0; i<N; i++)
    a[i] = line[i+1].split(' ');

for(var i=N-1; i>=0; i--){
    if(a[i][0]=="undo"){
        var timee = a[i][2] - a[i][1];
        
        for(var j=i-1; j>=0; j--){
            if(timee <= a[j][2]) a[j][0] = 0;
            else break;
        }
    }
}

for(var i=0; i<N; i++)
    if(a[i][0]=="type") process.stdout.write(a[i][1]);