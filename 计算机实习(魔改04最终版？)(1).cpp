#include<stdio.h>		//��׼��������ļ� 
#include<conio.h>		//ͨ������̨������������/����ĺ��� getch() 
#include<stdlib.h>		//���ƺ����������rand()/srand()�� �˳�exit() atio()�ַ���ת������������һ������
#include<time.h>		//����long clock()���ṹ��clock_t ���س���ʼִ�к�ռ�õĴ�����ʱ�� 
#include<string.h>		//�������� �ַ����Ⱥ���strlen���� �ȽϺ���strcmp���� 
#include<math.h>		//��ѧ������ 
#include<ctype.h>		//�ַ����Ժ������ַ�ӳ�亯�� isdigit()�ж��Ƿ���ʮ���������ַ� 
#define CLOCKS_PER_SEC 1000		//���������ʱ�н�����תΪ���� 

struct pupil 		// �����ṹ,ͬʱ�����û�ID���ɼ�������ʱ��
{	
	char ID[7];
	int grade;
	double  duration;
};

int IdCheck(char ID[]);		//����ID���麯�� 
char menu(); 			//����˵����� 
pupil problem();		//����Сѧ����Ŀ���� 
void write(pupil output);	//����ɼ�����д�뺯��	
void read(pupil input);		//����ɼ����ݶ��뺯�� 

int main()
{	
	int flag=0; 					// �ж�������ȷ�������ı��� 
	char option; 					//�ж��û�����ı��� 
	pupil input,temp; 				//����pupil�ͽṹ�壬�洢�û�ID���ɼ�������ʱ�� 
	printf("Please input your ID:  ");
	while(flag==0) 					//flag��Ϊ0���������IDͨ��
	{
		scanf("%s",input.ID); 		//�û�����ID 
		flag=IdCheck(input.ID); 	//�ж�ID�Ƿ�������ȷ 
	}
	option=menu(); 						//��ʾ�˵�����ȡ�û������ѡ�� 
	while(option!='3')
	{
		if(option=='1') 			//��ʼ������ϰ 
		{
			temp=problem(); 		//����ϰ����洢��temp�У���ֹID������ 
			input.grade=temp.grade; //���洢��temp�е���Ϣ���ݵ�input��
			input.duration=temp.duration; 
			write(input); 			//����������д���ı��ļ�"score.txt"
			printf("\nID:%6s\nGrade:%2d\nDuration:%.4fs\n\n",input.ID,input.grade,input.duration);
			printf("Press any key to return to the menu.");
			getch();
			printf("\n\n");
			option=menu();  //���ز˵�ѡ����»�ȡ���� 
		}
		else if(option=='2') //��ѯ����ʾ��ʷ��¼   
			{
				read(input); //��ȡ�ı��ļ����������ӦID��ʷ��¼ 
				printf("Press any key to return to the menu.\n\n");
				getch(); 
				option=menu(); 
		    }
		else //�����1��2��3 
		{
			printf("please enter a valid number!\n\n");//��ʾ������� 
			option=menu();  
		}
	}
		printf("\nBye!\n"); //�˳����� 
		return 0;
}

int IdCheck(char ID[]) //��������ID�Ƿ���ȷ���� 
{
    int i;
    if(strlen(ID)!=6) //�ж������ID�Ƿ�Ϊ6λ 
    {
    	printf("\nWrong ID! Press ESC to quit, or press any other key to try again.\n"); //�������ʱ�ṩ�˳�ѡ��
    	if(getch()==27)		//getch();����һ������������룬���ð��س��ͷ���
    	exit(0);
        printf("\nPlease input your ID( 2 capital letters followed by 4 digits): ");
        return 0; //����0��������� 
    } 
    if(ID[0]<'A'||ID[0]>'Z'||ID[1]<'A'||ID[1]>'Z') //�ж������IDǰ��λ�Ƿ��Ϊ��д��ĸ 
    {
    	printf("\nWrong ID! Press ESC to quit, or press any other key to try again.\n"); 
    	if(getch()==27)
    	exit(0);
        printf("\nPlease input your ID( 2 capital letters followed by 4 digits): ");
        return 0;
    }
    for(i=2;ID[i]!='\0';i++) //�ж������ID����λ�Ƿ��Ϊ���������� 
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
    return 1; //����1����������ͨ�� 
}

char menu() //��ʾ�˵�����
{
	char option[2];
    printf("\t\t\t\t\t ���������������������\n");
    printf("\t\t\t\t\t ��                MENU                ��\n");
    printf("\t\t\t\t\t ��     ��������������     ��\n");
    printf("\t\t\t\t\t ��                                    ��\n");
    printf("\t\t\t\t\t ��       ��1��  Start a test          ��\n");
    printf("\t\t\t\t\t ��                                    ��\n");
    printf("\t\t\t\t\t ��       ��2��  Check score           ��\n"); 
    printf("\t\t\t\t\t ��                                    ��\n");
    printf("\t\t\t\t\t ��       ��3��  Exit                  ��\n");
    printf("\t\t\t\t\t ��                                    ��\n");
    printf("\t\t\t\t\t ���������������������\n");
    printf("\n\n"); 
	printf("Please enter your option:");
    printf("\n"); 
	scanf("%s",option);
	if(strlen(option)==1) //�ж��û������Ƿ�Ϊһλ 
	return option[0];
	else
	return 0; //����0��ʾ������� 
}
	
pupil problem() //������⺯��
{ 
	printf("Let's begin!\n\n");
    int num_a[10],num_b[10],ture[10],answer_i[10]={0}; //num_a,num_b�����ʾ��������ture�����ʾ��ȷ�𰸣�answer_i�����ʾ���ε������ 
	char answer_a[10][10]; //answer_a�����ʾ�ַ��͵�����𰸣�����֮�����û��������Ƿ�Ϊ���� 
	int i,j;
	int temp; //��������������ʱʹ�õı��� 
	int flag=0; //������������Ҫ��ʱ��֤���������ı��� 
    char ops_temp[10];// ��¼ÿ�ε�������� 
    char ops[] = { '+','-','*','/'};
    pupil struc_temp;
    struc_temp.grade=0; //���ɼ���ʼ��Ϊ0 
    srand((unsigned)time(NULL)); //�������������ʼ����������Ϊ��ǰʱ�� unsigned(�޷������� 
	clock_t start, end;   //����clock_t�ͼ�ʱ���� 
    start = clock(); //��ʱ��ʼ 
    for(i=0;i<10;) //��10�� 
    {
        num_a[i]=rand()%99+1;	//�����������1��99֮������� +1�������0 
        num_b[i]=rand()%99+1;   
        if(flag==0) //������������Ҫ��ʱ��֤���������
        	ops_temp[i]= ops[ rand()%4]; //�����������һ�ּӡ������ˡ������� 
		if(ops_temp[i]=='+') //���Ϊ�ӷ� 
		{
			if(num_a[i]+num_b[i]>=100) //����������99 
			{
				flag=1;
				continue; //������Ҫ�󣬼���ѭ������ֻ�������������������������
			}
			else 
				ture[i]=num_a[i]+num_b[i];  //����������Ҫ��ʱ������ȷ�𰸴���key������ 
		}
		else if(ops_temp[i]=='-') //���Ϊ����
		{
			if(num_a[i]-num_b[i]<1) //����������
			{
				flag=1; 
				continue;
			}
			else 
				ture[i]=num_a[i]-num_b[i];  
		}
		else if(ops_temp[i]=='*')//���Ϊ�˷� 
		{
			if(num_a[i]*num_b[i]>99||num_a[i]==1||num_b[i]==1)//�����˻�����99
			{
				flag=1;
				continue;
			}
			else
				ture[i]=num_a[i]*num_b[i];  
		}
		else if(ops_temp[i]=='/') 
		{
			if(num_a[i]*num_b[i]>99||num_a[i]==1||num_b[i]==1)//�����˻�����99 
			{
				flag=1; 
				continue;
			}
			else
			{
				temp=num_a[i];  //������ʹԭ�ȵ������˻�Ϊ��������ԭ�ȵ�a[i]Ϊ������ԭ�ȵ�b[i]Ϊ�� 
				num_a[i]=num_a[i]*num_b[i];
				num_b[i]=temp;
				ture[i]=num_a[i]/num_b[i];				
			} 
		}
		printf("%-2d�� %2d %c %2d=",i+1,num_a[i],ops_temp[i],num_b[i]);//�����Ŀ 
		scanf("%s",&answer_a[i]);
 	    	for(j=0;answer_a[i][j]!='\0';j++)
 	    	{	
 	    		if(!isdigit(answer_a[i][j]))
 	    		{
 	    			j=0; 								
 	    			printf("Please enter a number:");	//���������ʱ���� 
 	    			scanf("%s",&answer_a[i][j]);
 	    			j--;
				}
			}
		answer_i[i]=atoi(answer_a[i]);//atoi������Ĵ𰸴��ַ���תΪ���� 
		if(answer_i[i]==ture[i])
           struc_temp.grade=struc_temp.grade+10;//���������ȷ���ɼ�+10�� 
 	    i++;
        flag=0;//���������������� 
    }
    end = clock();        //��ʱ���� 
    struc_temp.duration = (double)(end-start) / CLOCKS_PER_SEC; //�Ѻ���תΪ��
    printf("\n"); 
    printf("Prob.  |  Correct Answ.  |  Ur Answ.\n");
    for(i=0;i<10;i++)
    {
    	printf("%2d %c %2d	   %8d  	%8d\n",num_a[i],ops_temp[i],num_b[i],ture[i],answer_i[i]);
	}
	printf("\n");
	return struc_temp;//���洢��input�еĽ������������
}

void write(pupil output)//д�뺯��
{
    FILE *fp=NULL; //����fpָ�룬ָ��FILE���͵Ķ��󣬲���ʼ��Ϊ�� 
    fp=fopen("score.txt","a"); //���ļ�����Ϣ�ṹ���ַ�����ļ�ָ��fp�����ļ���
    if(fp==NULL)              //��һ��"a"ָ��һ���ı��ļ�����׷��ģʽд���ļ�������ļ������ڣ���ᴴ��һ�����ļ���
    { 
       printf("File open error!"); //������ļ�ʧ��,�˳����������� 
       return;
    }
    if(fprintf(fp,"%s\t%2d\t%f\n",output.ID,output.grade,output.duration)<=0)//��ѧ��������ʷ��¼�����ļ��У�����ֵ�����򱨴� 
       printf("File write error!\n");
    fclose(fp);//�ر��ļ� 
}

void read(pupil input)//��ȡ���� 
{
    FILE *fp;//����fpָ�룬ָ��FILE���͵Ķ���
    int flag=0;//��ʶ����Ϊ0��δ�ҵ���¼ 
    pupil output;//����һ��pupil�ͽṹ��
    fp=fopen("score.txt","r");	//�����r�����һ�����е��ı��ļ��������ȡ�ļ���
    if(fp==NULL) //������ļ�ʧ��,�˳����������� 
    {
       printf("\nFile open error!\n\n");
       return;
    }
    while(fscanf(fp,"%s\t%2d\t%lf\n",&output.ID,&output.grade,&output.duration)>0) //��ȡѧ��������ʷ��¼�������ļ�ĩβ�����ʱ����ѭ�� 
	{
    	if(strcmp(output.ID,input.ID)==0) //��ID����ƥ����������� 
    	{
        	flag=1; //flagΪ1 ʱ��ʾ����ʷ��¼ 
          	printf("ID��%-8sGrade��%2d\tDuration��%.4fs\n",output.ID,output.grade,output.duration);
    	}
	}
    if(flag==0) //flagΪ0��ʾ����ʷ��¼ 
    {
       printf("\nNo record found,please do a test first.\n\n");
          printf("\n");
    }
   	printf("\n"); 
}
