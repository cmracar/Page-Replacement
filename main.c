//
//  main.c
//  PageReplacement
//
//  Created by Cemre Acar on 14.12.2019.
//  Copyright © 2019 Cemre Acar. All rights reserved.
//

#include<stdio.h>


int n=23; // length of reference
int frame_no; // This is just for choice
int myno=3; // I gave this value 3 because we always solved 3 lines of graphics in the classroom.
int reference [] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 4, 3, 7, 6, 6, 5, 3, 2, 1, 2, 3, 6}; // This array expresses our values.
int c[50];
int hit=0; // check for hit
int x,y,z; // this is basic value for loop.
int countfault=0; // I count faults page here.
 
void init() // this is
{
    countfault=0;
    for(x=0; x<myno; x++)
        c[x]=9999;
}
 
int Hitt(int data) // It finds the required page in the Main Memory , this is "hit" , I determined it here.
{
    hit=0;
    for(y=0; y<myno; y++)
    {
        if(c[y]==data)
        {
            hit=1;
            break;
        }
 
    }
    return hit;
}
 
 
void Optimalreplacement() // Optimal algorithm implemented.
{
    init();
    int near[50];
    for(x=0; x<n; x++)
    {
 
        printf("\nIn %d =",reference[x]);
 
        if(Hitt(reference[x])==0)
        {
 
            for(y=0; y<myno; y++)
            {
                int pg=c[y];
                int findd=0;
                for(z=x; z<n; z++)
                {
                    if(pg==reference[z])
                    {
                        near[y]=z;
                        findd=1;
                        break;
                    }
                    else
                        findd=0;
                }
                if(!findd)
                    near[y]=9999;
            }
            int max=-9999;
            int reindex;
            for(y=0; y<myno; y++)
            {
                if(near[y]>max)
                {
                    max=near[y];
                    reindex=y;
                }
            }
            c[reindex]=reference[x];
            countfault++;
 
            for (z=0; z<myno; z++)
            {
            if(c[z]!=9999)
                printf(" %d",c[z]);
            }
        }
        else
            printf(" There is no page fault!");//It shows that there is fault each step .
    }
    printf("\nSum of page faults : %d",countfault);// I printed the total page faults.
}


void FIFOreplacement() // FIFO algorithm implemented.
{
    init();
    for(x=0; x<n; x++)
    {
        printf("\nIn %d =",reference[x]);
 
        if(Hitt(reference[x])==0)
        {
 
            for(z=0; z<myno-1; z++)
                c[z]=c[z+1];
 
            c[z]=reference[x];
            countfault++;
            for (z=0; z<myno; z++)
            {
            if(c[z]!=9999)
                printf(" %d",c[z]);
            }
        }
        else
            printf(" There is no page fault!");//It shows that there is fault each step .
    }
    printf("\nSum of page faults : %d",countfault); // I printed the total page faults.
}


void LRUreplacement() // LRU algorithm implemented.
{
    init();
 
    int least[50];
    for(x=0; x<n; x++)
    {
 
        printf("\nIn %d =",reference[x]);
 
        if(Hitt(reference[x])==0)
        {
 
            for(y=0; y<myno; y++)
            {
                int pg=c[y];
                int findd=0;
                for(z=x-1; z>=0; z--)
                {
                    if(pg==reference[z])
                    {
                        least[y]=z;
                        findd=1;
                        break;
                    }
                    else
                        findd=0;
                }
                if(!findd)
                    least[y]=-9999;
            }
            int min=9999;
            int reindex;
            for(y=0; y<myno; y++)
            {
                if(least[y]<min)
                {
                    min=least[y];
                    reindex=y;
                }
            }
            c[reindex]=reference[x];
            countfault++;
 
            for (z=0; z<myno; z++)
            {
            if(c[z]!=9999)
                printf(" %d",c[z]);
            }
        }
        else
            printf(" There is no page fault!");//It shows that there is fault each step .
    }
    printf("\nSum of page faults : %d",countfault); // I printed the total page faults.
}
 

 
int main()
{
    while(1)
    {
        printf("\n\nPage Replacement\n\n1-) FIFO replacement\n2-) Optimal replacement\n3-) LRU replacement\n\nWhich frames will apply ?\n\n");
        scanf("%d",&frame_no);
        switch(frame_no)
        {
        case 1:
            FIFOreplacement();
            break;
        case 2:
            Optimalreplacement();
            break;
        case 3:
            LRUreplacement();
            break;
        default:
            return 0;
            break;
        }
    }
}
