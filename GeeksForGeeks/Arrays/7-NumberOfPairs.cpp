// Number of pairs(Not submitted)
// 335 1 170 225 479 359 463 465 206 146 282 328 462 492 496 443 328 437 392 105 403 154 293 383 422 217 219 396 448 227 272 39 370 413 168 300 36 395 204 312 323 334
// 174 165 142 212 254 369 48 145 163 258 38 360 224 242 30 279 317 36 191 343 289 107 41 443 265 149 447 306 391 230 371 351 7 102 394 49 130 124 85 455 257 341 467 377 432 309 445 440 127 324 38 39 119 83 430 42 334 116 140 159 205 431 478 307 174 387 22 246

#include <iostream>
#include <algorithm>
using namespace std;

 int upperBound( int A, int B[], int N){
	 int L = 0;
	 int R = N-1;	
	while(L < R){
		 int mid = (L+R)/2;
		if((A < B[mid]) && A > B[mid - 1])
		    return mid;
		else if((A < B[mid]) && A < B[mid - 1])
			R = mid - 1;
		else
			L = mid + 1;
	}
	return L;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int M,N;
	    cin>>M>>N;
	    int X[M],Y[N],freq[5]={0},count=0;

	    for(int i=0;i<M;i++)
	        cin>>X[i];

		for(int i=0;i<N;i++){
	        cin>>Y[i];
			if(Y[i]<5)
        		freq[Y[i]]++;
		}
		sort(Y,Y+N);

		for(int i=0;i<N;i++)
			cout<<Y[i]<<" ";
		cout<<endl;

		for(int i=0;i<M;i++){
			int pos =0;
			if(X[i] == 0)
				continue;
			if(X[i] == 1){
				count = count + freq[0];
				continue;
			}


			pos = upperBound(X[i],Y,N);
			cout<<X[i]<<" "<<Y[pos]<<endl;
			if(X[i] < Y[pos])
				count = count + N - 1 - pos;
			else
				count = count + 1;

			count = count + freq[0] + freq[1];

			if(X[i] == 2)
				count = count - (freq[3] + freq[4]);
			if(X[i] == 3)
				count = count + freq[2];

		}

		cout<<count<<endl;

		
	}
	return 0;
}