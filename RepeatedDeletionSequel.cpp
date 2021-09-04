using pii = pair<int, int>;
pii st[100009];
int sl;
string solve(string s, int m) {
    int n = s.size();
    int i, j, k;
    sl = 1;
    st[0] = pii(0, 1);
    for(i=0;i<n;i++){
        st[sl].first=s[i];
        if(st[sl-1].first == s[i]){
            st[sl].second = st[sl-1].second + 1;
        }
        else{
            st[sl].second = 1;
        }
        sl++;
        if(st[sl-1].second >= m){
            sl -= m;
        }
    }
    string res;
    for(int i=1;i<sl;i++){
        res += st[i].first;
    }
    return res;
}