//program to implement page replacement algorithm LRU & FIFO

#include<stdio.h>
#include<stdlib.h>
int findLRU(int time[],int n)
{
        int i,min=time[0],pos=0;
        for(i=1;i<n;i++)
        {
                if(time[i]<min)
                {
                        min=time[i];
                        pos=i;
                }
         }
         return pos;
}

int main()
{
        int f,n,frames[10],pages[100],counter=0,time[10],flag1,flag2,i,j,k,avail,ch,fault=0,count=0,pos;
        
        printf("Enter the no of frames\t");
        scanf("%d",&f);
        printf("Enter the no of pages\t");
        scanf("%d",&n);
        
        printf("Enter the pages\n");
        for(i=0;i<n;i++)
                scanf("%d",&pages[i]);
                
        for(i=0;i<f;i++)
                frames[i]=-1;
        
        printf("\n 1.LRU\n 2.FIFO\n 3.EXIT\n");
        printf("Enter your choice \t");
        scanf("%d",&ch);
        
        switch(ch)
        {
                case 1:for(i=0;i<n;i++)
                        {
                                flag1=0;
                                flag2=0;
                                for(j=0;j<f;j++)
                                {
                                        if(frames[j]==pages[i])
                                        {
                                                counter++;
                                                time[j]=counter;
                                                flag1=flag2=1;
                                                break;
                                        }
                                }
                                if(flag1==0)
                                {
                                        for(j=0;j<f;j++)
                                        {
                                                if(frames[j]==-1)
                                                {
                                                        counter++;
                                                        time[j]=counter;
                                                        fault++;
                                                        frames[j]=pages[i];
                                                        flag2=1;
                                                        break;
                                                 }
                                         }
                                 }
                                 
                                 if(flag2==0)
                                 {
                                        pos=findLRU(time,f);
                                        counter++;
                                        time[pos]=counter;
                                        frames[pos]=pages[i];
                                        fault++;
                                 }
                                 printf("\n");
                                 for(j=0;j<f;j++)
                                        printf("%d\t",frames[j]);
                         }printf("Number of faults :%d\n",fault);
                         break;
                 
                case 2:j=0;
                       for(i=0;i<n;i++)
                       {
                                avail=0;
                                for(k=0;k<f;k++)
                                {
                                        if(frames[k]==pages[i])
                                                avail=1;
                                }
                                if(avail==0)
                                {
                                        frames[j]=pages[i];
                                        j=(j+1)%f;
                                        count++;
                                        for(k=0;k<f;k++)
                                                printf("%d\t",frames[k]);
                                        printf("\n");
                                 }
                        }
                          printf("Number of faults :%d\n",count);
                          break;
                case 3:exit(0);
                
                default:printf("Invalid choice\n");
       }
}
 
