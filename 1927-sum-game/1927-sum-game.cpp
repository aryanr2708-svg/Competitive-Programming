class Solution {
public:
    bool sumGame(string num) {
        int sl= 0;
        int sr= 0;
        int ql=0;
        int qr=0;
        for (int i=0;i<num.length();i++){
            if (i<num.length()/2){
                if (num[i] =='?'){
                   ql+=1;
                }
                else{
                   sl+=num[i]-'0';
                }
            }
            else{
                if (num[i] =='?'){
                   qr+=1;
                }
                else{
                   sr+=num[i]-'0';
                }
            }
        }
        if(ql+qr==0){
            return (sl!=sr);
        }
        if((ql+qr)%2!=0){
            return true;
        }
        if(ql==qr){
            return(sl!=sr);
        }
        return 2*(sl-sr)!=9*(qr-ql);
    }
};