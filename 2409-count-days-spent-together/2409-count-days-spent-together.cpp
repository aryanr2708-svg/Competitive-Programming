class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string st=max(arriveAlice,arriveBob);
        string lv=min(leaveAlice,leaveBob);
        if(st>lv){
            return 0;
        }
        int stm=stoi(st.substr(0,2));
        int std=stoi(st.substr(3,2));
        int lvm=stoi(lv.substr(0,2));
        int lvd=stoi(lv.substr(3,2));
        vector<int> months={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int td=0;
        if(stm==lvm){
            return lvd-std+1;
        }
        td+=(months[stm]-std+1);
        for(int m=stm+1;m<lvm;m++){
            td+=months[m];
        }
        td+=lvd;
        return td;
    }
};