#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <stdint.h>

#define u64 long long
#define endless true

#ifndef NYPC_GRADING
    #define REDIRECT_STDIN() freopen("input.txt","r",stdin)
    #define REDIRECT_STDOUT() freopen("ouput.txt","w",stdout)
#else
    #define REDIRECT_STDIN()
    #define REDIRECT_STDOUT()
#endif

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    REDIRECT_STDIN();
    REDIRECT_STDOUT();

    int a, b;
    cin >> a >> b;
    cout << a * b << endl;
    return 0;
}
