#include <iostream>

using namespace std;

int a[50005];
int ans = 0;
int n;

void guibin(int *a,int l,int r,int *temp)
{
    if (l < r)
    {
        int mid = (l + r) >> 1;
        guibin(a,l,mid,temp);
        guibin(a,mid+1,r,temp);

        int k = 0;

        int i = l;
        int j = mid + 1;

        while ((i <= mid) && (j <= r))
        {
            if (a[i] <= a[j])
            {
                temp[k++] = a[i++];
            }
            else
            {
                temp[k++] = a[j++];
                ans+=mid-i+1;
            }
        }


        while (i <= mid) temp[k++] = a[i++];
        while (j <= r) temp[k++] = a[j++];

        for (int x = 0; x < k;x++)
        {
            a[l+x] = temp[x];
        }

    }
}

int main()
{

    cin >> n;;

    for (int i = 1 ;i <= n;i++)
    {
        cin >> a[i];
    }

    int temp[50005];

    guibin(a,1,n,temp);

    /*for (int i = 1;i <= n;i++)
    {
        cout << a[i] << endl;
    }*/

    cout << ans;

    return 0;
}

