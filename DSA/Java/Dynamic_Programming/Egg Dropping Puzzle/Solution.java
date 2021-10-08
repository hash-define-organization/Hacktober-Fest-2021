class Solution 
{
	//Function to find minimum number of attempts needed in 
    //order to find the critical floor.
	static int eggDrop(int n, int k) 
	{ 
	    //creating a 2D table where entry eggFloor[i][j] will represent  
        //minimum number of trials needed for i eggs and j floors.
		int eggFloor[][] = new int[n+1][k+1]; 
		int res; 
		int i, j, x; 
		
		//we need one trial for one floor and 0 trials for 0 floors.
		for (i = 1; i <= n; i++) 
		{ 
			eggFloor[i][1] = 1; 
			eggFloor[i][0] = 0; 
		} 
		
	    //we always need j trials for one egg and j floors.
		for (j = 1; j <= k; j++) 
			eggFloor[1][j] = j; 
		
		//filling rest entries in table using optimal substructure property.
		for (i = 2; i <= n; i++) 
		{ 
			for (j = 2; j <= k; j++) 
			{ 
				eggFloor[i][j] = Integer.MAX_VALUE; 
				for (x = 1; x <= j; x++) 
				{ 
					res = 1 + Math.max(eggFloor[i-1][x-1], eggFloor[i][j-x]); 
					if (res < eggFloor[i][j]) 
						eggFloor[i][j] = res; 
				} 
			} 
		} 
		
		//returning the result in eggFloor[n][k].
		return eggFloor[n][k]; 

	} 
} 
