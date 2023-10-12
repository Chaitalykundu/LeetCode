class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int l=1, r=n-2, m, peak;
        while(l<r){
            m=l+(r-l)/2;
            int xl=mountainArr.get(m-1), 
            x=mountainArr.get(m),xr=mountainArr.get(m+1);
            if (xl<x && x>xr) {
                peak=m;
                break;
            }
            else if (x<xr)
                l=m+1;
            else
                r=m-1;
        }
        peak=r;
    //    cout<<"peak="<<peak<<endl;
        l=0, r=peak;
        while(l<r){
            m=l+(r-l)/2;
            int x=mountainArr.get(m);
            if (x==target) return m;
            else if (x<target) l=m+1;
            else r=m;
        }
    //    cout<<"not in the ascending part!\n";
        l=peak, r=n;
        while(l<r){
            m=l+(r-l)/2;
            int x=mountainArr.get(m);
            if (x==target) return m;
            else if (x>target) l=m+1;
            else r=m;
        }
        return -1;
    }
};