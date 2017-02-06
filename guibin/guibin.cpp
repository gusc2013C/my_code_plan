#include <iostream>

using namespace std;

int a[100];

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

    int n;

    cin >> n;;

    for (int i = 1 ;i <= n;i++)
    {
        cin >> a[i];
    }

    int temp[100];

    guibin(a,1,n,temp);

    for (int i = 1;i <= n;i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}
