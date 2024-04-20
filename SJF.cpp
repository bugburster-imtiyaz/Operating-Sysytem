#include <bits/stdc++.h>
using namespace std;

void runFCFS(int processes[], int arrival[], int burst[], int n)
{
    int completion[n], turnaround[n], waiting[n];
    vector<pair<int,int>> v;
    for(int i=0; i < n; i++)
    {
        v.push_back({burst[i], processes[i]});
    }
    sort(v.begin(), v.end());

    int clock=0, i=0, burst_time, process;
    while(i < n)
    {
        burst_time = v[i].first;
        process = v[i].second;
        if(clock < arrival[process])
        {
            clock = arrival[process];
        }
        clock += burst[process];
        completion[process] = clock;
        turnaround[process] = completion[process]-arrival[process];
        waiting[process] = turnaround[process]-burst[process];
        i++;
    }

    cout << "Pid Arrival Burst Completion Turnaround Waiting\n";

    for(int i=0; i < n; i++)
    {
        cout << processes[i] << "\t" << arrival[i] << "\t" << burst[i] << "\t" << completion[i] << "\t" << turnaround[i] << "\t" << waiting[i] << '\n';
    }
}

int main()
{
    int processes[] = {0, 1, 2, 3, 4};
    int arrival[] = {0, 8, 5, 5, 20};
    int burst[] = {2, 4, 6, 5, 7};
    int n= 5;

    runFCFS(processes, arrival, burst, n);

}


