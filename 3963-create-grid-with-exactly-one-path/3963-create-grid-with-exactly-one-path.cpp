class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>grid(m,string(n,'#'));
        int r=0,c=0;
        while(true){
            grid[r][c]='.';
            if(r==m-1 && c==n-1){
                break;
            }
            bool cr=(c+1<n);
            bool cd=(r+1<m);
            if(cr && cd){
                if(r==c){
                    c++;
                }
                else{
                    r++;
                }
            }
            else if(cr){
                c++;
            }
            else if(cd){
                r++;
            }
        }
        return grid;
    }
};