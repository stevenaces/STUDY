#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#define N 10
int N;
void Output(int track[],int num);
void FCFS(int track[],int num);
void SSTF(int track[],int num);
void SCAN(int track[],int num);
void CSCAN(int track[],int num);
int compInc(const void *a,const void *b) {
    return *(int *)a - *(int *)b;
}
int main() {
	while(1){
    int input,num;
    puts("请输入访问磁道的磁道数：");
    scanf("%d",&N);
    int track[N];
    srand((int)time(NULL));
    int i;
    for(i=0;i<N;i++) {
        track[i]=rand()%198+1;	//产生10个随机数作为磁盘队列 
        }
            printf("\n");
    num=rand()%198+1;	//产生当前磁头所在磁道 
    Output(track,num); 
    		printf("_________________________________________________________\n");
    		printf("*                                                       *\n");
            printf("*                        磁盘调度算法                   *\n");
            printf("*                                                       *\n");
            printf("*                     请选择要使用的算法                *\n");
            printf("*                                                       *\n");
            printf("*                 1、先来先服务调度算法(FCFS)           *\n");
            printf("*                 2、最短寻道时间优先调度算法(SSTF)     *\n");
            printf("*                 3、扫描调度算法(SCAN)                 *\n");
            printf("*                 4、循环扫描调度算法(C-SCAN）          *\n");
            printf("*                 5、调用以上四种算法，进行比较         *\n");
            printf("*                 6、退出                               *\n");
            printf("*                                                       *\n");
            printf("*                                                       *\n");
            printf("*                                                       *\n");
            printf("_________________________________________________________\n");
            printf("                  请选择算法：\n");
            scanf("%d",&input);
            printf("\n");
            switch(input) {
                case 1:
                    FCFS(track,num);
                    break;
                case 2:
                    SSTF(track,num);
                    break;
                case 3:
                    SCAN(track,num);
                    break;
                case 4:
                    CSCAN(track,num);
                    break;
                case 5:
                    FCFS(track,num);
                    SSTF(track,num);
                    SCAN(track,num);
                    CSCAN(track,num);
                    break;
                case 6:
                    exit(0);
                    break;
        }
    
}

}

void Output(int track[],int num)	//输出产生的磁道访问队列和磁头所在的磁道函数 
 {
    printf("请求磁道的序列为：") ;
    int i;
    for(i = 0; i < N; i++) {
        printf(" %d ",track[i]);
    }
    printf("\n");
    printf("当前所在磁道号为： %d\n",num);
}

void FCFS(int track[],int num) {
    int i;
    int sum = 0;
    double avg = 0.0;
    printf("*********************先来先服务调度算法**************************\n\n");
    Output(track,num);			//磁道输出显示 
    for(i = 0; i < N; i++)
     {
        if(num > track[i]){
            sum += num - track[i];
            printf("从%d磁道移动到%d磁道的距离为：%d\n",num,track[i],num-track[i]); 
			}
        else{
            sum += track[i] - num;
            printf("从%d磁道移动到%d磁道的距离为：%d\n",num,track[i],track[i]-num);
			}
            num = track[i];		//将磁头位置刷新 
    }
    avg = (double) sum / N;		//求平均寻道长度 
    printf("磁道访问队列为：");
    for(i = 0; i < N; i++)
        printf(" %d ",track[i]);
    printf("\n平均寻道长度为： %.2lf\n\n",avg);
}
void SSTF(int track[],int num) {
    int status[N];
    int ctrack[N];		//距离磁头的距离 
    int ttrack[N];		//记录磁头访问的序列 
    int sum = 0;
    double avg = 0.0;
    memset(status,0,sizeof(status));
    memset(ctrack,-1,sizeof(ctrack));
    int i,j;
    int min = 200;
    int minj = 0;
    printf("**********************最短寻道时间优先调度算法********************\n\n");
    Output(track,num);		//	显示函数 
    for(i = 0; i < N; i++) {
        min = 200;
        minj = 0;
        for(j = 0; j < N; j++) {
            if(status[j] == 1) {
                ctrack[j] = 200;		//将已访问的磁道距离当前磁头的长度置为200 
            }else {				//计算每个访问磁道距离当前磁头的距离 
                if(num > track[j]) 		//	刷新磁道队列距离当前磁头的距离 
					ctrack[j] = num - track[j];
                else 
					ctrack[j] = track[j] - num;
            }
        }
        for(j = 0; j < N; j++) {		//寻找最小距离的磁道位置 
            if(ctrack[j] <= min) {
                min = ctrack[j];
                minj = j;		//记下位置 
            }
        }
        printf("从%d磁道移动到%d磁道的距离为：%d\n",num,track[minj] ,ctrack[minj]);
        sum =sum+min;
        status[minj] = 1;		//已访问的磁道记录下来 
        num = track[minj];		//磁头位置刷新 
        ttrack[i] = num;		//记录磁头访问的磁道序列 
    }
    
    avg = (double) sum / N;    
    printf("磁道访问的序列为：");	   
    for(i=0;i<N;i++)
        printf(" %d ",ttrack[i]);
    printf("\n");
    printf("磁头移动总的磁道数为:%d",sum);
    printf("\n平均寻道长度为： %.2lf\n\n",avg);
}
void SCAN(int track[],int num) {
    int ctrack[N];	//从小到大排好序的磁道队列 
    int ttrack[N];	//记录磁头访问的序列 
    int i,choice;
    int sum = 0;
    double avg = 0.0;
    for(i = 0; i < N; i++) {
        ctrack[i] = track[i];
    }
    printf("*****************************扫描调度算法*******************************\n\n");
    Output(track,num);		//输出显示函数 
    qsort(ctrack,N,sizeof(ctrack[0]),compInc);
    if(num <= ctrack[0]) {	//磁头所在磁道比最小访问磁道还小
		puts("磁头所在磁道比最小访问磁道还小，磁头将向右移动"); 
        for(i = 0; i < N; i++) {
            sum += ctrack[i] - num;
            printf("从%d磁道移动到%d磁道的距离为：%d\n",num,ctrack[i] ,ctrack[i]-num);
            num = ctrack[i];
            ttrack[i] = num;
        }
    } else if(num >= ctrack[N-1]) {		//磁头所在磁道比最大的访问磁道还大
		puts("磁头所在磁道比最大的访问磁道还大，磁头将向左移动");		 
        for(i = N-1; i >= 0; i--) {
            sum += num - ctrack[i];
            printf("从%d磁道移动到%d磁道的距离为：%d\n",num,ctrack[i] ,abs(ctrack[i]-num));
            num = ctrack[i];
            ttrack[i] = num;
        }
    }else {
        int tmp1 = 0;	//磁头左边第一个访问磁道 
        int tmp2 = 0;	//磁头右边第一个访问磁道 
        for(i = 0; i < N; i++) {
            if(ctrack[i] <= num && ctrack[i+1] >= num) {	//不是上述两种情况，则找到磁道所在队列中的相对位置 
                tmp1 = i;
                tmp2 = i+1;
                break;
            }
        }
        puts("磁头在磁道访问串的中间"); 
        puts("磁头先向左移请输入数字：【1】|磁头先向右移请输入数字：【0】"); 
        puts("请选择磁头开始移动的方向：");
        scanf("%d",&choice);
        if(choice==0) {	//磁头向右的方向移动，再转向左 的程序段 
            int j = 0;
            for(i = tmp2; i < N; i++) {//向左 
                sum += ctrack[i] - num;
                if(i<N)
				{
					printf("从%d磁道移动到%d磁道的距离为：%d  右\n",num,ctrack[i] ,abs(ctrack[i]-num));
				} 
				
                num = ctrack[i];	//刷新磁头位置 
                ttrack[j++] = num;		//将访问的磁道记录到访问磁道序列	
            }
            sum=sum+(199-num)+(199-ctrack[tmp2]);
            num=ctrack[tmp2];
            for(i = tmp1;i >= 0; i--) { //向右         	
                sum += num - ctrack[i] ;
                if(num==ctrack[tmp2])
				{				
					printf("从%d磁道移动到%d磁道的距离为：%d   从 向右到向左\n",ctrack[N-1],ctrack[i] ,((199-ctrack[N-1])+(199-ctrack[i])));
					
                }
                else
					printf("从%d磁道移动到%d磁道的距离为：%d   左\n",num,ctrack[i] ,num-ctrack[i]);
                
                //printf("从%d磁道移动到%d磁道的距离为：%d\n",num,ctrack[i],num-ctrack[i]);
                num = ctrack[i];
                ttrack[j++] = num;		//刷新磁头位置 
            }
        }
		else {
            int j = 0;
            for(i = tmp1;i >= 0; i--) {
                sum += num - ctrack[i] ;
                if(i>=0)
				{
					printf("从%d磁道移动到%d磁道的距离为：%d  左\n",num,ctrack[i] ,abs(ctrack[i]-num));
				} 
                num = ctrack[i];
                ttrack[j++] = num;		//刷新磁头位置 
            }
            sum=sum+ctrack[0]+ctrack[tmp1];
            num=ctrack[tmp1];
            for(i = tmp2; i < N; i++) {
                sum += ctrack[i] - num;
                if(num==ctrack[tmp1])
				{				
					printf("从%d磁道移动到%d磁道的距离为：%d   从 向左向右\n",ctrack[0],ctrack[tmp2],(ctrack[0]+ctrack[tmp2]));
					
                }
                else
					printf("从%d磁道移动到%d磁道的距离为：%d   右\n",num,ctrack[i] ,abs(num-ctrack[i]));
                num = ctrack[i];
                ttrack[j++] = num;		//刷新磁头位置 
            }
        }
    }
    avg = (double) sum / N;
    
    printf("磁道访问的序列为：");
    for(i=0;i<N;i++)
        printf(" %d ",ttrack[i]);
    printf("\n");
    printf("磁头移动总的磁道数为:%d",sum); 
    printf("\n平均寻道长度为： %.2lf\n\n",avg);
}
void CSCAN(int track[],int num) {
    int ctrack[N];		//从小到大排好序的磁道队列 
    int ttrack[N];		//记录磁头访问的序列
    int i,choice;
    int sum = 0;
    double avg = 0.0;
    for(i = 0; i < N; i++) {
        ctrack[i] = track[i];
    }
    printf("*****************************循环扫描调度算法*******************************\n\n");
    Output(track,num);		//	显示函数 
    qsort(ctrack,N,sizeof(ctrack[0]),compInc);
    if(num <= ctrack[0]) {		//磁头所在磁道比最小访问磁道还小
        for(i = 0; i < N; i++) {
            sum += ctrack[i] - num;
            printf("从%d磁道移动到%d磁道的距离为：%d\n",num,ctrack[i] ,ctrack[i]-num);
            num = ctrack[i];
            ttrack[i] = num;		//记录磁头访问磁道序列 
        }
    } else if(num >= ctrack[N-1]) {		//磁头所在磁道比最大访问磁道还大 
    		sum=((199-num)+ctrack[0]);
    		num=ctrack[0];
        for(i = 1; i<N; i++) {
            sum += num - ctrack[i];
            printf("从%d磁道移动到%d磁道的距离为：%d\n",num,ctrack[i] ,ctrack[i]-num);
            num = ctrack[i];
            ttrack[i] = num;		//记录磁头访问磁道序列 
        }
    }else {
        int tmp1 = 0;	//当前磁头左边第一个磁道位置 
        int tmp2 = 0;	//当前磁头右边第一个磁道位置 
        for(i = 0; i < N; i++) {
            if(ctrack[i] <= num && ctrack[i+1] >= num) {		//不是上述两种情况，则找到磁道所在队列中的相对位置 
                tmp1 = i;
                tmp2 = i+1;
                break;
            }
        }
        puts("磁头先向左移请输入数字：【1】|磁头先向右移请输入数字：【0】"); 
        puts("请选择磁头开始移动的方向：");
        scanf("%d",&choice);
        if(choice==0){
            int j = 0;
            for(i = tmp2; i < N; i++) {
                sum += ctrack[i] - num;
                if(i<N){
                	printf("从%d磁道移动到%d磁道的距离为：%d    向右\n",num,ctrack[i] ,ctrack[i]-num);
                }
                num = ctrack[i];
                ttrack[j++] = num;
            }
            	sum=(sum+(199-ctrack[N-1])+ctrack[0]+199);
				num=ctrack[0];		//磁头位置刷新 
				ttrack[j++]=ctrack[0];
				printf("从%d磁道移动到%d磁道的距离为：%d    从右向左(%d,%d)\n",ctrack[N-1],ctrack[0],(((199-ctrack[N-1])+ctrack[0]+199)),ctrack[N-1],ctrack[0]);
            for(i = 0;i <= tmp1; i++) {
                sum += abs(num - ctrack[i]);
                //if(num==ctrack[0])
                //{
                //	printf("从%d磁道移动到%d磁道的距离为：%d    从右向左\n",ctrack[N-1],ctrack[0],(199-ctrack[N-1])+ctrack[0]+199);
                //}
                //else 
                if(i<tmp1)
                	printf("从%d磁道移动到%d磁道的距离为：%d	向右\n",num,ctrack[i+1],ctrack[i+1]-num);
                num = ctrack[i+1];
                ttrack[j++] = num;
            }
    	}
    	else{		//磁头向左移动，向右移动不访问 
    		int j=0;
    		for(i=tmp1;i>=0;i--){
    			sum +=num-ctrack[i];
    			if(i>=0){
    				printf("从%d磁道移动到%d磁道的距离为：%d    向右\n",num,ctrack[i] ,num-ctrack[i]);
    			}
    			num=ctrack[i];
    			ttrack[j++]=num;
    		}
    		sum=sum+((199-ctrack[N-1])+ctrack[0]+199);
    		num=ctrack[N-1];
    		ttrack[j++]=ctrack[N-1];
    		printf("从%d磁道移动到%d磁道的距离为：%d    从右向左(%d,%d)\n",ctrack[0],ctrack[N-1],(((199-ctrack[N-1])+ctrack[0]+199)),ctrack[N-1],ctrack[0]);
    		for(i=(N-1);i>=tmp1;i--){
    			sum += abs(num - ctrack[i]);
    			if(i>tmp2)
    				printf("从%d磁道移动到%d磁道的距离为：%d	向右\n",num,ctrack[i-1],num-ctrack[i-1]);
                num = ctrack[i-1];
                ttrack[j++] = num;
    		}
    	}
    }
    avg = (double)sum / N;
    printf("磁道访问的序列为：");
    for( i=0;i<N;i++)
        printf(" %d ",ttrack[i]);
    printf("\n");
    printf("磁头移动总的磁道数为:%d",sum); 
    printf("\n平均寻道长度为： %.2lf\n\n",avg);
    }
