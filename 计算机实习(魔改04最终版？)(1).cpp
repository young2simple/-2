#include<stdio.h>		//标准输入输出文件 
#include<conio.h>		//通过控制台进行数据输入/输出的函数 getch() 
#include<stdlib.h>		//控制函数：随机数rand()/srand()、 退出exit() atio()字符串转换成整型数的一个函数
#include<time.h>		//函数long clock()；结构体clock_t 返回程序开始执行后占用的处理器时间 
#include<string.h>		//包含函数 字符长度函数strlen（） 比较函数strcmp（） 
#include<math.h>		//数学函数库 
#include<ctype.h>		//字符测试函数、字符映射函数 isdigit()判断是否是十进制数字字符 
#define CLOCKS_PER_SEC 1000		//方便后续计时中将毫秒转为秒用 

struct pupil 		// 声明结构,同时定义用户ID、成绩与做题时间
{	
	char ID[7];
	int grade;
	double  duration;
};

int IdCheck(char ID[]);		//定义ID检验函数 
char menu(); 			//定义菜单函数 
pupil problem();		//定义小学生题目函数 
void write(pupil output);	//定义成绩数据写入函数	
void read(pupil input);		//定义成绩数据读入函数 

int main()
{	
	int flag=0; 					// 判断输入正确与否情况的变量 
	char option; 					//判断用户输入的变量 
	pupil input,temp; 				//声明pupil型结构体，存储用户ID、成绩与做题时间 
	printf("Please input your ID:  ");
	while(flag==0) 					//flag不为0代表输入的ID通过
	{
		scanf("%s",input.ID); 		//用户输入ID 
		flag=IdCheck(input.ID); 	//判断ID是否输入正确 
	}
	option=menu(); 						//显示菜单并获取用户输入的选项 
	while(option!='3')
	{
		if(option=='1') 			//开始计算练习 
		{
			temp=problem(); 		//将练习情况存储至temp中，防止ID被覆盖 
			input.grade=temp.grade; //将存储在temp中的信息传递到input中
			input.duration=temp.duration; 
			write(input); 			//将上述内容写入文本文件"score.txt"
			printf("\nID:%6s\nGrade:%2d\nDuration:%.4fs\n\n",input.ID,input.grade,input.duration);
			printf("Press any key to return to the menu.");
			getch();
			printf("\n\n");
			option=menu();  //返回菜单选项并重新获取输入 
		}
		else if(option=='2') //查询并显示历史记录   
			{
				read(input); //读取文本文件，并输出对应ID历史记录 
				printf("Press any key to return to the menu.\n\n");
				getch(); 
				option=menu(); 
		    }
		else //输入非1或2或3 
		{
			printf("please enter a valid number!\n\n");//提示输入错误 
			option=menu();  
		}
	}
		printf("\nBye!\n"); //退出程序 
		return 0;
}

int IdCheck(char ID[]) //检验输入ID是否正确函数 
{
    int i;
    if(strlen(ID)!=6) //判断输入的ID是否为6位 
    {
    	printf("\nWrong ID! Press ESC to quit, or press any other key to try again.\n"); //输入错误时提供退出选项
    	if(getch()==27)		//getch();接受一个任意键的输入，不用按回车就返回
    	exit(0);
        printf("\nPlease input your ID( 2 capital letters followed by 4 digits): ");
        return 0; //返回0则输入错误 
    } 
    if(ID[0]<'A'||ID[0]>'Z'||ID[1]<'A'||ID[1]>'Z') //判断输入的ID前两位是否均为大写字母 
    {
    	printf("\nWrong ID! Press ESC to quit, or press any other key to try again.\n"); 
    	if(getch()==27)
    	exit(0);
        printf("\nPlease input your ID( 2 capital letters followed by 4 digits): ");
        return 0;
    }
    for(i=2;ID[i]!='\0';i++) //判断输入的ID后四位是否均为阿拉伯数字 
    {
        if(!isdigit(ID[i]))
        {
        	printf("\nWrong ID! Press ESC to quit, or press any other key to try again.\n"); 
    		if(getch()==27)		
    		exit(0);
            printf("\nPlease input your ID( 2 capital letters followed by 4 digits): ");
            return 0;
        }  
    }
    printf("\n");
    return 1; //返回1，代表输入通过 
}

char menu() //显示菜单函数
{
	char option[2];
    printf("\t\t\t\t\t ★★★★★★★★★★★★★★★★★★★★\n");
    printf("\t\t\t\t\t ★                MENU                ★\n");
    printf("\t\t\t\t\t ★     ●●●●●●●●●●●●●     ★\n");
    printf("\t\t\t\t\t ★                                    ★\n");
    printf("\t\t\t\t\t ★       （1）  Start a test          ★\n");
    printf("\t\t\t\t\t ★                                    ★\n");
    printf("\t\t\t\t\t ★       （2）  Check score           ★\n"); 
    printf("\t\t\t\t\t ★                                    ★\n");
    printf("\t\t\t\t\t ★       （3）  Exit                  ★\n");
    printf("\t\t\t\t\t ★                                    ★\n");
    printf("\t\t\t\t\t ★★★★★★★★★★★★★★★★★★★★\n");
    printf("\n\n"); 
	printf("Please enter your option:");
    printf("\n"); 
	scanf("%s",option);
	if(strlen(option)==1) //判断用户输入是否为一位 
	return option[0];
	else
	return 0; //返回0表示输入错误 
}
	
pupil problem() //随机出题函数
{ 
	printf("Let's begin!\n\n");
    int num_a[10],num_b[10],ture[10],answer_i[10]={0}; //num_a,num_b数组表示运算数，ture数组表示正确答案，answer_i数组表示整形的输入答案 
	char answer_a[10][10]; //answer_a数组表示字符型的输入答案，用来之后检查用户的输入是否为数字 
	int i,j;
	int temp; //除法交换运算数时使用的变量 
	int flag=0; //运算结果不符合要求时保证运算符不变的变量 
    char ops_temp[10];// 记录每次的运算符号 
    char ops[] = { '+','-','*','/'};
    pupil struc_temp;
    struc_temp.grade=0; //将成绩初始化为0 
    srand((unsigned)time(NULL)); //随机数发生器初始化，种子数为当前时间 unsigned(无符号数） 
	clock_t start, end;   //定义clock_t型计时变量 
    start = clock(); //计时开始 
    for(i=0;i<10;) //共10题 
    {
        num_a[i]=rand()%99+1;	//随机生成两个1至99之间的整数 +1避免出现0 
        num_b[i]=rand()%99+1;   
        if(flag==0) //运算结果不符合要求时保证运算符不变
        	ops_temp[i]= ops[ rand()%4]; //随机生成任意一种加、减、乘、除运算 
		if(ops_temp[i]=='+') //如果为加法 
		{
			if(num_a[i]+num_b[i]>=100) //运算结果大于99 
			{
				flag=1;
				continue; //不符合要求，继续循环，且只重新生成运算数，运算符不变
			}
			else 
				ture[i]=num_a[i]+num_b[i];  //运算结果符合要求时，将正确答案存入key数组中 
		}
		else if(ops_temp[i]=='-') //如果为减法
		{
			if(num_a[i]-num_b[i]<1) //运算结果非正
			{
				flag=1; 
				continue;
			}
			else 
				ture[i]=num_a[i]-num_b[i];  
		}
		else if(ops_temp[i]=='*')//如果为乘法 
		{
			if(num_a[i]*num_b[i]>99||num_a[i]==1||num_b[i]==1)//两数乘积大于99
			{
				flag=1;
				continue;
			}
			else
				ture[i]=num_a[i]*num_b[i];  
		}
		else if(ops_temp[i]=='/') 
		{
			if(num_a[i]*num_b[i]>99||num_a[i]==1||num_b[i]==1)//两数乘积大于99 
			{
				flag=1; 
				continue;
			}
			else
			{
				temp=num_a[i];  //交换以使原先的两数乘积为被除数，原先的a[i]为除数，原先的b[i]为答案 
				num_a[i]=num_a[i]*num_b[i];
				num_b[i]=temp;
				ture[i]=num_a[i]/num_b[i];				
			} 
		}
		printf("%-2d） %2d %c %2d=",i+1,num_a[i],ops_temp[i],num_b[i]);//输出题目 
		scanf("%s",&answer_a[i]);
 	    	for(j=0;answer_a[i][j]!='\0';j++)
 	    	{	
 	    		if(!isdigit(answer_a[i][j]))
 	    		{
 	    			j=0; 								
 	    			printf("Please enter a number:");	//输入非数字时报错 
 	    			scanf("%s",&answer_a[i][j]);
 	    			j--;
				}
			}
		answer_i[i]=atoi(answer_a[i]);//atoi将输入的答案从字符型转为整形 
		if(answer_i[i]==ture[i])
           struc_temp.grade=struc_temp.grade+10;//如果输入正确，成绩+10分 
 	    i++;
        flag=0;//继续随机生成运算符 
    }
    end = clock();        //计时结束 
    struc_temp.duration = (double)(end-start) / CLOCKS_PER_SEC; //把毫秒转为秒
    printf("\n"); 
    printf("Prob.  |  Correct Answ.  |  Ur Answ.\n");
    for(i=0;i<10;i++)
    {
    	printf("%2d %c %2d	   %8d  	%8d\n",num_a[i],ops_temp[i],num_b[i],ture[i],answer_i[i]);
	}
	printf("\n");
	return struc_temp;//将存储在input中的结果返回主函数
}

void write(pupil output)//写入函数
{
    FILE *fp=NULL; //声明fp指针，指向FILE类型的对象，并初始化为空 
    fp=fopen("score.txt","a"); //将文件的信息结构体地址赋给文件指针fp并打开文件，
    if(fp==NULL)              //上一行"a"指打开一个文本文件，以追加模式写入文件。如果文件不存在，则会创建一个新文件。
    { 
       printf("File open error!"); //如果打开文件失败,退出函数并报错 
       return;
    }
    if(fprintf(fp,"%s\t%2d\t%f\n",output.ID,output.grade,output.duration)<=0)//将学生答题历史记录输入文件中，返回值非正则报错 
       printf("File write error!\n");
    fclose(fp);//关闭文件 
}

void read(pupil input)//读取函数 
{
    FILE *fp;//声明fp指针，指向FILE类型的对象
    int flag=0;//标识符，为0则未找到记录 
    pupil output;//声明一个pupil型结构体
    fp=fopen("score.txt","r");	//这里的r代表打开一个已有的文本文件，允许读取文件。
    if(fp==NULL) //如果打开文件失败,退出函数并报错 
    {
       printf("\nFile open error!\n\n");
       return;
    }
    while(fscanf(fp,"%s\t%2d\t%lf\n",&output.ID,&output.grade,&output.duration)>0) //读取学生答题历史记录，读至文件末尾或出错时跳出循环 
	{
    	if(strcmp(output.ID,input.ID)==0) //若ID号相匹配则输出数据 
    	{
        	flag=1; //flag为1 时表示有历史记录 
          	printf("ID：%-8sGrade：%2d\tDuration：%.4fs\n",output.ID,output.grade,output.duration);
    	}
	}
    if(flag==0) //flag为0表示无历史记录 
    {
       printf("\nNo record found,please do a test first.\n\n");
          printf("\n");
    }
   	printf("\n"); 
}
