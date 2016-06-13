#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
char gpass[20];
struct music
{
	char mn[50];
	char an[50];
	char sn[50];
	char size[10];
};
struct music m;
void pass();
void add();
void wel();
void load();
void menu();
void search();
void terminate();
void del();
void playlist();
void show();
void change_pass();
void mshow(struct music);
void ashow(struct music);
void sshow(struct music);
void adel(char *);
void sdel(char *);
void msearch(struct music);
void asearch(struct music);
void ssearch(struct music);
void mdel(char *);
void update(char *);
void main()
{
	FILE *fp;
	int gd=DETECT,gm,i=0,cnt=0;
	char ch;
	initgraph(&gd,&gm,"c:/turboc3/bgi");
	fp=fopen("pass.txt","a");	//creat file
	setbkcolor(GREEN);
	setcolor(BLUE);
	if(fp==NULL)
	{
		cleardevice();
		outtextxy(40,100,"Sorry, the password containing file is not found");
		outtextxy(40,140,"Plz enter a new password to enter to the program");
		outtextxy(40,197,"Enter your password :");
		gotoxy(28,13);
		flushall();
	       REPEAT:
	       while(1)
		{
			ch=getch();
			printf("*");
			if(ch=='\r')
			{
				printf("\b \b");
				break;
			}
			if(ch==8)
			{
			     if(i!=0)
			     {
				printf("\b \b\b \b");
				i--;
			     }
			     else
			     {
				printf("\b \b");
			     }
			}
			if(ch!=8)
			{
				gpass[i]=ch;
				i++;
				cnt++;
			}
			if(cnt>12)
			{
				outtextxy(250,400,"Limit exceeding");
				delay(500);
				goto REPEAT;
			}	//End of if
		 }	//End of loop
		 gpass[i]='\0';
		fprintf(fp,"%s",gpass);
	}	//End of loop
	fclose(fp);	// close file
	setbkcolor(YELLOW);
	wel();
	pass();
	menu();
}
void pass()
{
	int i=0,cnt,j;
	char p[30],p1[30],c,ch;
	FILE *fp;
	REPEAT:
	cleardevice();
	setbkcolor(YELLOW);
	setcolor(RED);
	fp=fopen("pass.txt","r");
	for(j=0;j<3;j++)
	{
		cleardevice();
		settextstyle(8,0,5);
		outtextxy(210,50,"SECURITY");
		settextstyle(0,0,1);
		setfillstyle(SOLID_FILL,BLUE);
		bar(225,195,365,275);
		setfillstyle(SOLID_FILL,RED);
		bar(230,200,360,270);
		setfillstyle(HATCH_FILL,BLUE);
		bar(240,230,350,260);
		setcolor(YELLOW);
		outtextxy(255,210,"PASSWORD");
		setcolor(RED);
		settextstyle(0,0,1);
		outtextxy(350,400,"type EXIT to exit the prog.");
		gotoxy(32,16);
		cnt=0;
		i=0;
		while(1)
		{
			ch=getch();
			printf("*");
			if(ch=='\r')
			{
				printf("\b \b");
				break;
			}
			if(ch==8)
			{
			     if(i!=0)
			     {
				printf("\b \b\b \b");
				i--;
			     }
			     else
			     {
				printf("\b \b");
			     }
			}
			if(ch!=8)
			{
				p[i]=ch;
				i++;
				cnt++;
			}
			if(cnt>12)
			{
				outtextxy(250,400,"Limit exceeding");
				delay(500);
				goto REPEAT;
			}	//End of if
		 }	//End of loop
		 p[i]='\0';
		 fscanf(fp,"%s",gpass);
		 if(strcmp(p,gpass)==0)
		 {
			menu();
			break;
		 }
		 else if(strcmpi(p,"exit")==0)
		 {
			setfillstyle(SOLID_FILL,YELLOW);
			bar(350,400,570,420);
			outtextxy(50,400,"Do you sure to exit the program [y/n]");
			fflush(stdin);
			c=getche();
			if(c=='y')
			{
				outtextxy(200,430,"THANX FOR VISIT...!!!");
				getch();
				closegraph();
			}
			else if(c=='n')
			{
				pass();
				break;
			}
			else
			{
				outtextxy(150,430,"Plz enter a valid choice....");
				getch();
			}	//End of if
		 }
		 else
		 {
			setfillstyle(SOLID_FILL,YELLOW);
			bar(350,400,570,420);
			outtextxy(50,400,"password is incorrect...!!! plz try again....");
			getch();
		 }	//End of if
	}	//End of loop
	cleardevice();
	outtextxy(50,100,"You give wrong username or password 3 times...");
	outtextxy(50,130,"so we exit the program...!!!");
	getch();
	closegraph();
}
void menu()
{
	int i;
	char n[20],k,c,ch;
//	load();
	while(1)
	{
		cleardevice();
		setbkcolor(YELLOW);
		setcolor(RED);
		settextstyle(8,0,1);
		for(i=1;i<=5;i++)
		{
			rectangle(186+i,45+i,366-i,85-i);
			rectangle(0+i,0+i,getmaxx()-i,getmaxy()-i);
		}	//End of loop
		outtextxy(200,50,"MUSIC LIBRARY");
		settextstyle(0,0,1);
		outtextxy(50,100,"1 - ADD SONGS");
		outtextxy(50,125,"2 - SHOW SONGS");
		outtextxy(50,150,"3 - SEARCH SONG");
		outtextxy(50,175,"4 - DELETE SONG");
		outtextxy(50,200,"5 - UPDATE SONG");
		outtextxy(50,225,"6 - CHANGE PASSWORD");
		outtextxy(50,250,"7 - EXIT");
		outtextxy(200,400,"enter your choice");
		ch=getche();
		switch(ch)
		{
			case '1':add();
			break;
			case '2':show();
			break;
			case '3':search();
			break;
			case '4':del();
			break;
			case '5':cleardevice();
			settextstyle(8,0,1);
			outtextxy(250,50,"UPDATE MENU");
			settextstyle(0,0,1);
			outtextxy(350,400,"type BACK to main menu");
			outtextxy(350,420,"type EXIT to exit the prog.");
			outtextxy(40,100,"Enter name of song to be updated : ");
			gotoxy(42,7);
			flushall();
			gets(n);
			if(strlen(n)<50)
			{
				if(n[i]=='\0')
					strcpy(n,"UNKNOWN");
				else if(strcmp(n,"back")==0)
					menu();
				else if(strcmpi(n,"exit")==0)
				{
					outtextxy(50,400,"Do you sure to exit the program [y/n]");
					fflush(stdin);
					c=getche();
					if(c=='y')
					{
						outtextxy(200,430,"THANX FOR VISIT...!!!");
						getch();
						closegraph();
					}
					else if(c=='n')
						menu();
					else
					{
						outtextxy(50,430,"Plz enter a valid choice....");
						getch();
					}
				}
				else
					update(n);
			}
			else
			{
				setfillstyle(SOLID_FILL,YELLOW);
				bar(300,390,600,450);
				outtextxy(50,400,"Music name's size is out of range");
				getch();
			}
			break;
			case '6':change_pass();
			break;
			case '7':setfillstyle(SOLID_FILL,YELLOW);
				 bar(50,400,500,440);
				outtextxy(50,400,"Do you sure to exit the program [y/n]");
				fflush(stdin);
				c=getche();
				if(c=='y')
				{
					outtextxy(200,430,"THANX FOR VISIT...!!!");
					getch();
					closegraph();
				}
				else if(c=='n')
					menu();
				else
				{
					outtextxy(150,430,"Plz enter a valid choice....");
					getch();
				}
			default:setfillstyle(SOLID_FILL,YELLOW);
			bar(50,400,500,450);
			outtextxy(200,400,"WRONG CHOICE");
			getch();
		}
	}	//End of loop
}
void add()
{
	FILE *fp,*ft;
	int i=0;
	char another='y',c,ch,c1;
	fp=fopen("music.txt","a+");
	ft=fopen("playlist.txt","a+");
	do
	{
		cleardevice();
		settextstyle(8,0,1);
		outtextxy(250,50,"ADD MUSIC");
		settextstyle(0,0,1);
		outtextxy(350,400,"type BACK to main menu");
		outtextxy(350,420,"type EXIT to exit the prog.");
		outtextxy(50,116,"Enter music name :-");
		gotoxy(28,8);
		flushall();
		gets(m.mn);
		if(strlen(m.mn)<50)
		{
			i=0;
			if(m.mn[i]=='\0')
				strcpy(m.mn,"UNKNOWN");
			else if(strcmpi(m.mn,"back")==0)
				menu();
			else if(strcmpi(m.mn,"exit")==0)
			{
				setfillstyle(SOLID_FILL,YELLOW);
				bar(350,400,570,440);
				outtextxy(50,400,"Do you sure to exit the program [y/n]");
				fflush(stdin);
				c=getche();
				if(c=='y')
				{
					outtextxy(200,430,"THANX FOR VISIT...!!!");
					getch();
					closegraph();
				}
				else if(c=='n')
					menu();
				else
				{
					outtextxy(150,430,"Plz enter a valid choice....");
					getch();
					setfillstyle(SOLID_FILL,YELLOW);
					bar(50,400,500,500);
				}
			}
		}
		else
		{
			setfillstyle(SOLID_FILL,YELLOW);
			bar(300,390,600,450);
			outtextxy(50,400,"Music naem's size is out of range");
			getch();
			break;
		}
		outtextxy(50,148,"Enter album name :-");
		gotoxy(28,10);
		flushall();
		gets(m.an);
		if(strlen(m.an)<50)
		{
			i=0;
			if(m.an[i]=='\0')
				strcpy(m.an,"UNKNOWN");
			else if(strcmpi(m.an,"back")==0)
				menu();
			else if(strcmpi(m.an,"exit")==0)
			{
				setfillstyle(SOLID_FILL,YELLOW);
				bar(350,400,570,440);
				outtextxy(50,400,"Do you sure to exit the program [y/n]");
				fflush(stdin);
				c=getche();
				if(c=='y')
				{
					outtextxy(200,430,"THANX FOR VISIT...!!!");
					getch();
					closegraph();
				}
				else if(c=='n')
					menu();
				else
				{
					outtextxy(150,430,"Plz enter a valid choice....");
					getch();
					setfillstyle(SOLID_FILL,YELLOW);
					bar(50,400,500,500);
				}
			}
		}
		else
		{
			setfillstyle(SOLID_FILL,YELLOW);
			bar(300,390,600,450);
			outtextxy(50,400,"Album name's size is out of range");
			getch();
			break;
		}
		outtextxy(50,180,"Enter singer name :-");
		gotoxy(28,12);
		flushall();
		gets(m.sn);
		if(strlen(m.sn)<50)
		{
			i=0;
			if(m.sn[i]=='\0')
				strcpy(m.sn,"UNKNOWN");
			else if(strcmpi(m.sn,"back")==0)
				menu();
			else if(strcmpi(m.sn,"exit")==0)
			{
				setfillstyle(SOLID_FILL,YELLOW);
				bar(350,400,570,440);
				outtextxy(50,400,"Do you sure to exit the program [y/n]");
				fflush(stdin);
				c=getche();
				if(c=='y')
				{
					outtextxy(200,430,"THANX FOR VISIT...!!!");
					getch();
					closegraph();
				}
				else if(c=='n')
					menu();
				else
				{
					outtextxy(150,430,"Plz enter a valid choice....");
					getch();
					setfillstyle(SOLID_FILL,YELLOW);
					bar(50,400,500,500);
				}
			}
		}
		else
		{
			setfillstyle(SOLID_FILL,YELLOW);
			bar(300,390,600,450);
			outtextxy(50,400,"Singer name's size is out of range");
			getch();
			break;
		}
		outtextxy(50,212,"Enter music size :-");
		gotoxy(28,14);
		flushall();
		gets(m.size);
		if(strlen(m.size)<50)
		{
			if(strcmpi(m.size,"back")==0)
				menu();
			else if(strcmpi(m.size,"exit")==0)
			{
				setfillstyle(SOLID_FILL,YELLOW);
				bar(350,400,570,440);
				outtextxy(50,400,"Do you sure to exit the program [y/n]");
				fflush(stdin);
				c=getche();
				if(c=='y')
				{
					outtextxy(200,430,"THANX FOR VISIT...!!!");
					getch();
					exit(0);
					closegraph();
				}
				else if(c=='n')
					menu();
				else
				{
					outtextxy(50,430,"Plz enter a valid choice....");
					getch();
					setfillstyle(SOLID_FILL,YELLOW);
					bar(150,400,500,500);
				}
			}
		}
		else
		{
			setfillstyle(SOLID_FILL,YELLOW);
			bar(300,390,600,450);
			outtextxy(50,400,"Music detail's size is out of range");
			getch();
			break;
		}
		outtextxy(50,250,"DO YOU WANT TO ADD THIS SONG TO PLAYLIST [y/n]");
		c1=getche();
		if(c1=='y')
			fwrite(&m,sizeof(m),1,ft);
		else if((c1!='y') && (c1!='n'))
		{
			outtextxy(100,270,"Plz enter valid choice");
			getch();
			setfillstyle(SOLID_FILL,YELLOW);
			bar(50,250,600,300);
		}
		setfillstyle(SOLID_FILL,YELLOW);
		bar(350,400,600,450);
		outtextxy(50,400,"WANT TO ADD MORE MUSIC SONGS [y/n]");
		flushall();
		another=getche();
		fwrite(&m,sizeof(m),1,fp);
	}while(another=='y');
	fcloseall();
}
void show()
{
	int i;
	char c,ch;
	while(1)
	{
		cleardevice();
		settextstyle(8,0,1);
		outtextxy(200,50,"SHOW MENU");
		settextstyle(0,0,1);
		outtextxy(40,100,"1 - Show according to songs");
		outtextxy(40,125,"2 - Show according to albums");
		outtextxy(40,150,"3 - Show according to artists");
		outtextxy(40,175,"4 - Show playlist");
		outtextxy(40,200,"5 - Back");
		outtextxy(40,225,"6 - Exit");
//		outtextxy(40,227,"Enter your choice : ");
		ch=getche();
		switch(ch)
		{
			case '1':mshow(m);
			break;
			case '2':ashow(m);
			break;
			case '3':sshow(m);
			break;
			case '4':playlist();
			break;
			case '5':menu();
			break;
			case '6':outtextxy(50,400,"Do you sure to exit the program [y/n]");
			fflush(stdin);
			c=getche();
			if(c=='y')
			{
				outtextxy(200,430,"THANX FOR VISIT...!!!");
				getch();
				closegraph();
			}
			else if(c=='n')
			{
				menu();
				break;
			}
			else
			{
				outtextxy(150,430,"Plz enter a valid choice....");
				getch();
			}
			default:setfillstyle(SOLID_FILL,YELLOW);
			bar(50,400,500,500);
			outtextxy(200,400,"WRONG CHOICE");
			getch();
		}
	}
}
void mshow(struct music m)
{
	FILE *fp;
	int i=0,ch,y;
	char c,x;
	fp=fopen("music.txt","r");
	cleardevice();
	settextstyle(8,0,1);
	outtextxy(200,30,"LIST OF MUSIC");
	settextstyle(0,0,1);
	if(feof(fp))
	{
		outtextxy(50,125,"SORRY.....there is no songs.....   !!!");
		outtextxy(50,150,"Press 1 to go to main menu");
		outtextxy(50,175,"Press 2 to back");
		outtextxy(50,200,"Press 3 to exit");
		ch=getche();
		switch(ch)
		{
			case '1':menu();
			break;
			case '2':show();
			break;
			case '3':outtextxy(50,400,"Do you sure to exit the program [y/n]");
			fflush(stdin);
			c=getche();
			if(c=='y')
			{
				outtextxy(200,430,"THANX FOR VISIT...!!!");
				getch();
				closegraph();
			}
			else if(c=='n')
			{
				menu();
				break;
			}
			else
			{
				outtextxy(150,430,"Plz enter a valid choice....");
				getch();
			}
			default:outtextxy(50,400,"WRONG CHOICE");
		}
	}
	outtextxy(50,70,"Music name");
	outtextxy(300,70,"Music size");
	settextstyle(0,0,1);
	y=110;
	for(i=0;(fread(&m,sizeof(m),1,fp)==1);i++)
	{
		outtextxy(50,y,m.mn);
		outtextxy(300,y,m.size);
		y=y+30;
		delay(150);
		if(y>370)
		{
			REPEAT:
			outtextxy(50,400,"DO YOU WANT TO SEE MORE SONGS [y/n] : ");
			x=getche();
			if(x=='y')
			{
				cleardevice();
				y=100;
				settextstyle(8,0,1);
				outtextxy(200,30,"LIST OF MUSIC");
				settextstyle(0,0,1);
				outtextxy(50,70,"Music name");
				outtextxy(300,70,"Music size");
				settextstyle(0,0,1);
				continue;
			}
			else if(x=='n')
			{
				show();
				break;
			}
			else
			{
				outtextxy(150,430,"Wrong choice");
				getch();
				setfillstyle(SOLID_FILL,YELLOW);
				bar(50,420,500,500);
				goto REPEAT;
			}
		}
	}
	fclose(fp);
	getch();
}
void ashow(struct music m)
{
	FILE *fp;
	int i=0,ch,y;
	char str[50];
	char x,c;
	str[50]='\0';
	fp=fopen("music.txt","r");
	cleardevice();
	settextstyle(8,0,1);
	outtextxy(200,30,"LIST OF ALBUMS");
	settextstyle(0,0,1);
	if(feof(fp))
	{
		outtextxy(50,125,"SORRY.....there is no albums...   !!!");
		outtextxy(50,150,"Press 1 to go to main menu");
		outtextxy(50,175,"Press 2 to back");
		outtextxy(50,200,"Press 3 to exit");
		ch=getche();
		switch(ch)
		{
			case '1':menu();
			break;
			case '2':show();
			break;
			case '3':outtextxy(50,400,"Do you sure to exit the program [y/n]");
			fflush(stdin);
			c=getche();
			if(c=='y')
			{
				outtextxy(200,430,"THANX FOR VISIT...!!!");
				getch();
				closegraph();
			}
			else if(c=='n')
			{
				menu();
				break;
			}
			else
			{
				outtextxy(150,430,"Plz enter a valid choice....");
				getch();
			}
			default: outtextxy(150,400,"WRONG CHOICE");
		}
	}
	outtextxy(50,70,"ALBUM NAME");
	y=110;
	for(i=0;(fread(&m,sizeof(m),1,fp)==1);i++)
	{
		if(strcmp(str,m.an)==0)
			continue;
		strcpy(str,m.an);
		settextstyle(0,0,1);
		outtextxy(50,y,m.an);
		delay(150);
		y=y+30;
		if(y>370)
		{
			REPEAT:
			outtextxy(50,400,"DO YOU WANT TO SEE MORE SONGS [y/n]");
			fflush(stdin);
			x=getche();
			if(x=='y')
			{
				cleardevice();
				y=110;
				settextstyle(8,0,1);
				outtextxy(100,30,"LIST OF ALBUMS");
				settextstyle(0,0,1);
				outtextxy(50,70,"ALBUM NAME");
				continue;
			}
			else if(x=='n')
			{
				show();
				break;
			}
			else
			{
				outtextxy(150,430,"Wrong choice");
				getch();
				goto REPEAT;
			}
		}

	}
	fclose(fp);
	getch();
}
void sshow(struct music m)
{
	FILE *fp;
	int i=0,y;
	char str[50];
	char x,ch,c;
	str[50]='\0';
	fp=fopen("music.txt","r");
	cleardevice();
	settextstyle(8,0,1);
	outtextxy(200,30,"LIST OF SINGERS");
	settextstyle(0,0,1);
	if(feof(fp))
	{
		outtextxy(50,125,"SORRY.....there is no singers...   !!!");
		outtextxy(50,150,"Press 1 to go to main menu");
		outtextxy(50,175,"Press 2 to back");
		outtextxy(50,200,"Press 3 to exit");
		ch=getche();
		switch(ch)
		{
			case '1':menu();
			break;
			case '2':show();
			break;
			case '3':outtextxy(50,400,"Do you sure to exit the program [y/n]");
			fflush(stdin);
			c=getche();
			if(c=='y')
			{
				outtextxy(200,430,"THANX FOR VISIT...!!!");
				getch();
				closegraph();
			}
			else if(c=='n')
			{
				menu();
				break;
			}
			else
			{
				outtextxy(50,430,"Plz enter a valid choice....");
				getch();
			}
			default: outtextxy(150,400,"WRONG CHOICE");
		}
	}
	outtextxy(50,70,"SINGER NAME");
	y=110;
	for(i=0;(fread(&m,sizeof(m),1,fp)==1);i++)
	{
		if(strcmp(str,m.sn)==0)
			continue;
		strcpy(str,m.sn);
		settextstyle(0,0,1);
		outtextxy(50,y,m.sn);
		delay(150);
		y=y+30;
		if(y>370)
		{
			REPEAT:
			outtextxy(50,400,"DO YOU WANT TO SEE MORE SONGS [y/n]");
			fflush(stdin);
			x=getche();
			if(x=='y')
			{
				cleardevice();
				settextstyle(1,0,3);
				outtextxy(200,30,"LIST OF SINGERS");
				settextstyle(1,0,2);
				outtextxy(50,70,"SINGER NAME");
				y=110;
				continue;
			}
			else if(x=='n')
			{
				show();
				break;
			}
			else
			{
				outtextxy(150,430,"Wrong choice");
				getch();
				goto REPEAT;
			}
		}
	}
	fclose(fp);
	getch();
}
void playlist()
{
	FILE *fp;
	int i=0,ch,y;
	char c,x;
	fp=fopen("playlist.txt","r");
	cleardevice();
	settextstyle(8,0,1);
	outtextxy(200,30,"MY PLAYLIST");
	settextstyle(0,0,1);
	if(feof(fp))
	{
		outtextxy(50,125,"SORRY.....there is no songs.....   !!!");
		outtextxy(50,150,"Press 1 to go to main menu");
		outtextxy(50,175,"Press 2 to back");
		outtextxy(50,200,"Press 3 to exit");
		ch=getche();
		switch(ch)
		{
			case '1':menu();
			break;
			case '2':show();
			break;
			case '3':outtextxy(50,400,"Do you sure to exit the program [y/n]");
			fflush(stdin);
			c=getche();
			if(c=='y')
			{
				outtextxy(200,430,"THANX FOR VISIT...!!!");
				getch();
				closegraph();
			}
			else if(c=='n')
			{
				menu();
				break;
			}
			else
			{
				outtextxy(150,430,"Plz enter a valid choice....");
				getch();
			}
			default:outtextxy(50,400,"WRONG CHOICE");
		}
	}
	outtextxy(50,70,"Music name");
	outtextxy(300,70,"Music size");
	settextstyle(0,0,1);
	y=110;
	for(i=0;(fread(&m,sizeof(m),1,fp)==1);i++)
	{
		outtextxy(50,y,m.mn);
		outtextxy(300,y,m.size);
		y=y+30;
		delay(150);
		if(y>370)
		{
			REPEAT:
			outtextxy(50,400,"DO YOU WANT TO SEE MORE SONGS [y/n] : ");
			x=getche();
			if(x=='y')
			{
				cleardevice();
				y=100;
				settextstyle(8,0,1);
				outtextxy(200,30,"MY PLAYLIST");
				settextstyle(0,0,1);
				outtextxy(50,70,"Music name");
				outtextxy(300,70,"Music size");
				settextstyle(0,0,1);
				continue;
			}
			else if(x=='n')
			{
				show();
				break;
			}
			else
			{
				outtextxy(150,430,"Wrong choice");
				getch();
				setfillstyle(SOLID_FILL,YELLOW);
				bar(50,420,500,500);
				goto REPEAT;
			}
		}
	}
	fclose(fp);
	getch();
}
void search()
{
	int i;
	char c,ch;
	clrscr();
	while(1)
	{
		cleardevice();
		settextstyle(8,0,1);
		outtextxy(200,50,"SEARCH MENU");
		settextstyle(0,0,1);
		outtextxy(50,100,"1 - Search according to music's name");
		outtextxy(50,125,"2 - Search according to album's name");
		outtextxy(50,150,"3 - Search according to singer's name");
		outtextxy(50,175,"4 - Back");
		outtextxy(50,200,"5 - Exit");
//		outtextxy(50,245,"Enter your choice : ");
		ch=getche();
		switch(ch)
		{
			case '1':msearch(m);
			break;
			case '2':asearch(m);
			break;
			case '3':ssearch(m);
			break;
			case '4':menu();
			break;
			case '5':REPEAT:
			outtextxy(50,400,"Do you sure to exit the program [y/n]");
			fflush(stdin);
			c=getche();
			if(c=='y')
			{
				setfillstyle(SOLID_FILL,YELLOW);
				bar(40,430,400,500);
				outtextxy(200,430,"THANX FOR VISIT...!!!");
				getch();
				closegraph();
			}
			else if(c=='n')
			{
				menu();
				break;
			}
			else
			{
				outtextxy(50,430,"Plz enter a valid choice....");
				getch();
				goto REPEAT;
			}
			default:setfillstyle(SOLID_FILL,YELLOW);
			bar(50,400,500,500);
			outtextxy(200,400,"WRONG CHOICE");
			getch();
		}
	}
}
void msearch(struct music m)
{
	FILE *fp;
	int i=0,f=0,y;
	char n[20],c,k,ch,c2;
	cleardevice();
	settextstyle(8,0,1);
	outtextxy(200,50,"SEARCH ANY MUSIC");
	fp=fopen("music.txt","r");
	settextstyle(0,0,1);
	outtextxy(350,400,"type BACK to main menu");
	outtextxy(350,420,"type EXIT to exit the prog.");
	outtextxy(50,100,"Enter songs name : ");
	gotoxy(26,7);
	flushall();
	gets(n);
	if(strlen(n)<50)
	{
		setfillstyle(SOLID_FILL,YELLOW);
		bar(350,400,570,440);
		i=0;
		if(n[i]=='\0')
			strcpy(n,"UNKNOWN");
		else if(strcmp(n,"menu")==0)
		{
			menu();
		}
		else if(strcmp(n,"back")==0)
		{
			search();
		}
		else if(strcmpi(n,"exit")==0)
		{
			REPEAT:
			outtextxy(50,400,"Do you sure to exit the program [y/n]");
			fflush(stdin);
			c=getche();
			if(c=='y')
			{
				outtextxy(200,430,"THANX FOR VISIT...!!!");
				getch();
				closegraph();
			}
			else if(c=='n')
			{
				menu();
			}
			else
			{
				outtextxy(50,430,"Plz enter a valid choice....");
				setfillstyle(SOLID_FILL,YELLOW);
				bar(50,400,500,500);
				goto REPEAT;
			}
		}
		else
		{
			i=0;
			y=150;
			settextstyle(0,0,1);
			while(fread(&m,sizeof(m),1,fp)==1)
			{
			    if(strcmp(m.mn,n)==0)
			    {
				outtextxy(50,y,"Music name : ");
				outtextxy(200,y,m.mn);
				outtextxy(50,y+20,"Album name : ");
				outtextxy(200,y+20,m.an);
				outtextxy(50,y+40,"Singer name : ");
				outtextxy(200,y+40,m.sn);
				outtextxy(50,y+60,"Music size : ");
				outtextxy(200,y+60,m.size);
				f=1;
			    }
			}
		}
		if(f==1)
		{
			outtextxy(50,300,"press 1 for delete");
			outtextxy(50,320,"press 2 for update");
			outtextxy(50,340,"press 0 for back");
			ch=getche();
			if(ch=='1')
			{
				outtextxy(50,400,"Do you sure to delete the song [y/n]");
				fflush(stdin);
				c=getche();
				if(c=='y')
				{
					mdel(n);
				}
				else if(c=='n')
					return;
				else
				{
					outtextxy(50,430,"Plz enter a valid choice...");
					getch();
				}
			}
			else if(ch=='2')
			{
				outtextxy(50,400,"Do you sure to update the song [y/n]");
				fflush(stdin);
				c=getche();
				if(c=='y')
				{
					cleardevice();
					update(n);
				}
				else if(c=='n')
					return;
				else
				{
					setfillstyle(SOLID_FILL,YELLOW);
					bar(50,420,500,500);
					outtextxy(50,430,"WRONG CHOICE");
					getch();
				}
			}
			else if(ch=='0')
			{
				search();
			}
			else
			{
			   setfillstyle(SOLID_FILL,YELLOW);
			   bar(50,420,500,500);
			   outtextxy(50,430,"WRONG CHOICE");
			   getch();
			}
		}
		fclose(fp);
	}
	else
	{
		setfillstyle(SOLID_FILL,YELLOW);
		bar(300,390,600,450);
		outtextxy(50,400,"Music name's size is out of range");
		getch();
		search();
	}
}
void asearch(struct music m)
{
	FILE *fp;
	int i=0,f=0,y;
	char n[20],c,k,ch,c1;
	fp=fopen("music.txt","r");
	fp=fopen("music.txt","r");
	cleardevice();
	settextstyle(8,0,1);
	outtextxy(200,50,"SEARCH ANY ALBUM");
	settextstyle(0,0,1);
	outtextxy(350,400,"type BACK to main menu");
	outtextxy(350,420,"type EXIT to exit the prog.");
	outtextxy(50,100,"Enter album name : ");
	gotoxy(26,7);
	flushall();
	gets(n);
	if(strlen(n)<50)
	{
		setfillstyle(SOLID_FILL,YELLOW);
		bar(350,400,570,440);
		i=0;
		if(n[i]=='\0')
			strcpy(n,"UNKNOWN");
		else if(strcmp(n,"menu")==0)
		{
			menu();
		}
		else if(strcmp(n,"back")==0)
		{
			search();
		}
		else if(strcmpi(n,"exit")==0)
		{
			REPEAT:
			outtextxy(50,400,"Do you sure to exit the program [y/n]");
			fflush(stdin);
			c=getche();
			if(c=='y')
			{
				outtextxy(200,430,"THANX FOR VISIT...!!!");
				getch();
				closegraph();
			}
			else if(c=='n')
			{
				menu();
			}
			else
			{
				outtextxy(50,430,"Plz enter a valid choice....");
				setfillstyle(SOLID_FILL,YELLOW);
				bar(50,400,500,500);
				goto REPEAT;
			}
		}
		else
		{
			y=150;
			settextstyle(0,0,1);
			while(fread(&m,sizeof(m),1,fp)==1)
			{
			    if(strcmp(m.an,n)==0)
			    {
				outtextxy(50,y,"Music name : ");
				outtextxy(200,y,m.mn);
				outtextxy(50,y+20,"Album name : ");
				outtextxy(200,y+20,m.an);
				outtextxy(50,y+40,"Singer name : ");
				outtextxy(200,y+40,m.sn);
				outtextxy(50,y+60,"Music size : ");
				outtextxy(200,y+60,m.size);
				y=y+90;
				f=1;
			    }
			    if(y>370)
			    {
				outtextxy(50,420,"DO YOU WANT TO SEE MORE SONGS [y/n] : ");
				c1=getche();
				if(c1=='y')
				{
					cleardevice();
					y=100;
					settextstyle(8,0,1);
					outtextxy(200,50,"SEARCH ANY ALBUM");
					settextstyle(0,0,1);
					continue;
				}
				else if(c1=='n')
				{
					search();
					break;
				}
				else
				{
					outtextxy(50,450,"Wrong choice");
					getch();
					setfillstyle(SOLID_FILL,YELLOW);
					bar(50,420,500,500);
				}
			    }
			}
		}
		if(f==1)
		{
			outtextxy(50,420,"Press '1' for delete the album or '0' for back...");
			ch=getche();
			if(ch=='1')
			{
				cleardevice();
				outtextxy(100,200,"Do you sure to delete the album [y/n]");
				fflush(stdin);
				c=getche();
				if(c=='y')
				{
					adel(n);
				}
				else if(c=='n')
					return;
				else
				{
					outtextxy(200,420,"WRONG CHOICE");
					getch();
				}
			}
			else if(ch=='0')
			{
				search();
			}
			else
			{
			   outtextxy(50,400,"WRONG CHOICE");
			   getch();
			}
		}
		fclose(fp);
	}
	else
	{
		setfillstyle(SOLID_FILL,YELLOW);
		bar(300,390,600,450);
		outtextxy(50,400,"Album name's size is out of range");
		getch();
		search();
	}
}
void ssearch(struct music m)
{
	FILE *fp;
	int i=0,ch,f=0,y;
	char n[20],c,k,c1;
	fp=fopen("music.txt","r");
	fp=fopen("music.txt","r");
	cleardevice();
	settextstyle(8,0,1);
	outtextxy(150,50,"SEARCH SONGS OF ANY SINGER");
	settextstyle(0,0,1);
	outtextxy(350,400,"type BACK to main menu");
	outtextxy(350,420,"type EXIT to exit the prog.");
	outtextxy(50,100,"Enter singer name : ");
	gotoxy(28,7);
	flushall();
	gets(n);
	if(strlen(n)<50)
	{
		setfillstyle(SOLID_FILL,YELLOW);
		bar(350,400,570,440);
		i=0;
		if(n[i]=='\0')
			strcpy(n,"UNKNOWN");
		else if(strcmp(n,"menu")==0)
		{
			menu();
		}
		else if(strcmp(n,"back")==0)
		{
			search();
		}
		else if(strcmpi(n,"exit")==0)
		{
			REPEAT:
			outtextxy(50,400,"Do you sure to exit the program [y/n]");
			fflush(stdin);
			c=getche();
			if(c=='y')
			{
				outtextxy(200,430,"THANX FOR VISIT...!!!");
				getch();
				closegraph();
			}
			else if(c=='n')
			{
				menu();
			}
			else
			{
				outtextxy(50,430,"Plz enter a valid choice....");
				setfillstyle(SOLID_FILL,YELLOW);
				bar(50,400,500,500);
				goto REPEAT;
			}
		}
		else
		{
			y=150;
			i=0;
			settextstyle(0,0,1);
			while(fread(&m,sizeof(m),1,fp)==1)
			{
			    if(strcmp(m.sn,n)==0)
			    {
				outtextxy(50,y,"Music name : ");
				outtextxy(200,y,m.mn);
				outtextxy(50,y+20,"Album name : ");
				outtextxy(200,y+20,m.an);
				outtextxy(50,y+40,"Singer name : ");
				outtextxy(200,y+40,m.sn);
				outtextxy(50,y+60,"Music size : ");
				outtextxy(200,y+60,m.size);
				y=y+90;
				f=1;
			    }
			    if(y>370)
			    {
				outtextxy(50,420,"DO YOU WANT TO SEE MORE SONGS [y/n] : ");
				c1=getche();
				if(c1=='y')
				{
					cleardevice();
					y=100;
					settextstyle(8,0,1);
					outtextxy(150,50,"SEARCH SONGS OF ANY SINGER");
					settextstyle(0,0,1);
					continue;
				}
				else if(c1=='n')
				{
					search();
					break;
				}
				else
				{
					outtextxy(50,450,"Wrong choice");
					getch();
					setfillstyle(SOLID_FILL,YELLOW);
					bar(50,420,500,500);
				}
			    }
			}
		}
		settextstyle(0,0,1);
		if(f==1)
		{
			outtextxy(50,420,"Press '1' for delete the album or '0' for back...");
			ch=getche();
			if(ch=='1')
			{
				cleardevice();
				outtextxy(100,200,"Do you sure to delete the album [y/n]");
				fflush(stdin);
				c=getche();
				if(c=='y')
				{
					adel(n);
				}
				else if(c=='n')
					return;
				else
				{
					outtextxy(200,420,"WRONG CHOICE");
					getch();
				}
			}
			else if(ch=='0')
			{
				search();
			}
			else
			{
			   outtextxy(50,400,"WRONG CHOICE");
			   getch();
			}
		}
		fclose(fp);
	}
	else
	{
		setfillstyle(SOLID_FILL,YELLOW);
		bar(300,390,600,450);
		outtextxy(50,400,"Singer name's size is out of range");
		getch();
		search();
	}
}
void del()
{
	int i,f=1;
	char n[20];
	char c,ch,c1;
	FILE *fp;
	fp=fopen("music.txt","r");
	while(1)
	{
		cleardevice();
		settextstyle(8,0,1);
		outtextxy(200,50,"DELETE MENU");
		settextstyle(0,0,1);
		outtextxy(50,100,"1 - Remove according to music's name");
		outtextxy(50,125,"2 - Remove according to album's name");
		outtextxy(50,150,"3 - Remove according to singer's name");
		outtextxy(50,175,"4 - Back");
		outtextxy(50,200,"5 - Exit");
//		outtextxy(50,245,"Enter your choice : ");
		ch=getche();
		switch(ch)
		{
			case '1':cleardevice();
			settextstyle(8,0,1);
			outtextxy(250,50,"REMOVE ANY MUSIC");
			settextstyle(0,0,1);
			outtextxy(350,400,"type BACK to main menu");
			outtextxy(350,420,"type EXIT to exit the prog.");
			outtextxy(40,117,"Enter name of song to be deleted : ");
			gotoxy(42,8);
			flushall();
			gets(n);
			if(strlen(n)<50)
			{
				flushall();
				setfillstyle(SOLID_FILL,YELLOW);
				bar(350,400,570,440);
				if(n[i]=='\0')
					strcpy(n,"UNKNOWN");
				else if(strcmp(n,"back")==0)
				{
					menu();
					break;
				}
				else if(strcmpi(n,"exit")==0)
				{
					outtextxy(50,400,"Do you sure to exit the program [y/n]");
					fflush(stdin);
					c=getche();
					if(c=='y')
					{
						outtextxy(200,430,"THANX FOR VISIT...!!!");
						getch();
						closegraph();
					}
					else if(c=='n')
					{
						menu();
						break;
					}
					else
					{
						outtextxy(50,430,"Plz enter a valid choice....");
						setfillstyle(SOLID_FILL,YELLOW);
						bar(50,400,500,500);
					}
				}
				else
				{
					while(fread(&m,sizeof(m),1,fp)==1)
					{
						if(strcmp(m.mn,n)==0)
						{
							f=0;
							break;
						}
						else
							f=1;
					}
					if(f==1)
					{
						outtextxy(50,400,"This song doesn't exist in this library");
						getch();
						del();
						break;
					}
					while((c1!='y') || (c1!='n'))
					{
						outtextxy(50,400,"Do you sure to remove the music [y/n]");
						fflush(stdin);
						c1=getche();
						if(c1=='y')
						{
							mdel(n);
							break;
						}
						else if(c1=='n')
						{
							menu();
							break;
						}
						else
						{
							outtextxy(50,430,"Plz enter a valid choice....");
							setfillstyle(SOLID_FILL,YELLOW);
							bar(50,400,500,500);
						}
					}
				}
			}
			else
			{
				setfillstyle(SOLID_FILL,YELLOW);
				bar(300,390,600,450);
				outtextxy(50,400,"Music name's size is out of range");
				getch();
			}
			break;
			case '2':cleardevice();
			settextstyle(8,0,1);
			outtextxy(250,50,"REMOVE ANY ALBUM");
			settextstyle(0,0,1);
			outtextxy(350,400,"type BACK to main menu");
			outtextxy(350,420,"type EXIT to exit the prog.");
			outtextxy(40,116,"Enter name of album to be deleted : ");
			gotoxy(43,8);
			flushall();
			gets(n);
			if(strlen(n)<50)
			{
				setfillstyle(SOLID_FILL,YELLOW);
				bar(350,400,570,440);
				if(n[i]=='\0')
					strcpy(n,"UNKNOWN");
				else if(strcmp(n,"back")==0)
				{
					menu();
					break;
				}
				else if(strcmpi(n,"exit")==0)
				{
					outtextxy(50,400,"Do you sure to exit the program [y/n]");
					fflush(stdin);
					c=getche();
					if(c=='y')
					{
						outtextxy(200,430,"THANX FOR VISIT...!!!");
						getch();
						closegraph();
					}
					else if(c=='n')
					{
						menu();
						break;
					}
					else
					{
						outtextxy(50,430,"Plz enter a valid choice....");
						setfillstyle(SOLID_FILL,YELLOW);
						bar(50,400,500,500);
					}
				}
				else
				{
					while(fread(&m,sizeof(m),1,fp)==1)
					{
						if(strcmp(m.an,n)==0)
						{
							f=0;
							break;
						}
					}
					if(f==1)
					{
						outtextxy(50,400,"This singer doesn't exist in this library");
						getch();
						del();
						break;
					}
					while((c1!='y') || (c1!='n'))
					{
							outtextxy(50,400,"Do you sure to remove the album [y/n]");
						fflush(stdin);
						c1=getche();
						if(c1=='y')
						{
							adel(n);
							break;
						}
						else if(c1=='n')
						{
							menu();
							break;
						}
						else
						{
							outtextxy(50,430,"Plz enter a valid choice....");
							getch();
							setfillstyle(SOLID_FILL,YELLOW);
							bar(50,400,500,500);
						}
					}
				}
			}
			else
			{
				setfillstyle(SOLID_FILL,YELLOW);
				bar(300,390,600,450);
				outtextxy(50,400,"Album name 's size is out of range");
				getch();
			}
			break;
			case '3':cleardevice();
			settextstyle(8,0,1);
			outtextxy(150,50,"REMOVE SONGS OF ANY SINGER");
			settextstyle(0,0,1);
			outtextxy(350,400,"type BACK to main menu");
			outtextxy(350,420,"type EXIT to exit the prog.");
			outtextxy(40,116,"Enter name of singer to be deleted : ");
			gotoxy(43,8);
			flushall();
			gets(n);
			if(strlen(n)<50)
			{
				setfillstyle(SOLID_FILL,YELLOW);
				bar(350,400,570,440);
				if(n[i]=='\0')
					strcpy(n,"UNKNOWN");
				else if(strcmp(n,"back")==0)
				{
					menu();
					break;
				}
				else if(strcmpi(n,"exit")==0)
				{
					outtextxy(50,400,"Do you sure to exit the program [y/n]");
					fflush(stdin);
					c=getche();
					if(c=='y')
					{
						outtextxy(200,430,"THANX FOR VISIT...!!!");
						getch();
						closegraph();
					}
					else if(c=='n')
					{
						menu();
						break;
					}
					else
					{
						outtextxy(50,430,"Plz enter a valid choice....");
						setfillstyle(SOLID_FILL,YELLOW);
						bar(50,400,500,500);
					}
				}
				else
				{
					while(fread(&m,sizeof(m),1,fp)==1)
					{
						if(strcmp(m.sn,n)==0)
						{
							f=0;
							break;
						}
					}
					if(f==1)
					{
						outtextxy(50,400,"This singer doesn't exist in this library");
						getch();
						del();
						break;
					}
					while((c1!='y') || (c1!='n'))
					{
						outtextxy(50,400,"Do you sure to remove the singer [y/n]");
						fflush(stdin);
						c1=getche();
						if(c1=='y')
						{
							sdel(n);
							break;
						}
						else if(c1=='n')
						{
							menu();
							break;
						}
						else
						{
							outtextxy(50,430,"Plz enter a valid choice....");
							setfillstyle(SOLID_FILL,YELLOW);
							bar(50,400,500,500);
						}
					}
				}
			}
			else
			{
				setfillstyle(SOLID_FILL,YELLOW);
				bar(300,390,600,450);
				outtextxy(50,400,"Singer name's size is out of range");
				getch();
			}
			break;
			case '4':menu();
			break;
			case '5':outtextxy(50,400,"Do you sure to exit the program [y/n]");
				fflush(stdin);
				c=getche();
				if(c=='y')
				{
					outtextxy(200,430,"THANX FOR VISIT...!!!");
					getch();
					closegraph();
				}
				else if(c=='n')
				{
					menu();
					break;
				}
				else
				{
					outtextxy(100,430,"Plz enter a valid choice....");
					setfillstyle(SOLID_FILL,YELLOW);
					bar(50,400,500,500);
				}
			default:setfillstyle(SOLID_FILL,YELLOW);
			bar(50,400,500,500);
			outtextxy(200,400,"WRONG CHOICE");
			getch();
		}
	}
}
void mdel(char *n)
{
	FILE *fp,*ft,*fa,*fb;
	char k,c;
	fp=fopen("music.txt","r");
	ft=fopen("abc.txt","a+");
	fa=fopen("playlist.txt","r");
	fb=fopen("xyz.txt","a+");
	while(fread(&m,sizeof(m),1,fp)==1)
	{
	    if(strcmpi(m.mn,n)!=0)
	    {
		fwrite(&m,sizeof(m),1,ft);
	    }
	}
	while(fread(&m,sizeof(m),1,fa)==1)
	{
		if(strcmpi(m.mn,n)!=0)
		{
			fwrite(&m,sizeof(m),1,fb);
		}
	}
	fcloseall();
	remove("music.txt");
	rename("abc.txt","music.txt");
	remove("playlist.txt");
	rename("xyz.txt","playlist.txt");
}
void adel(char *n)
{
	FILE *fp,*ft,*fa,*fb;
	char k,c;
	fp=fopen("music.txt","r");
	ft=fopen("abc.txt","a+");
	fa=fopen("playlist.txt","r");
	fb=fopen("xyz.txt","a+");
	while(fread(&m,sizeof(m),1,fp)==1)
	{
	    if(strcmpi(m.an,n)!=0)
	    {
		fwrite(&m,sizeof(m),1,ft);
	    }
	}
	while(fread(&m,sizeof(m),1,fa)==1)
	{
		if(strcmpi(m.an,n)!=0)
		{
			fwrite(&m,sizeof(m),1,fb);
		}
	}
	fcloseall();
	remove("music.txt");
	rename("abc.txt","music.txt");
	remove("playlist.txt");
	rename("xyz.txt","playlist.txt");
}
void sdel(char *n)
{
	FILE *fp,*ft,*fa,*fb;
	char k,c;
	fp=fopen("music.txt","r");
	ft=fopen("abc.txt","a+");
	fa=fopen("playlist.txt","r");
	fb=fopen("xyz.txt","a+");
	while(fread(&m,sizeof(m),1,fp)==1)
	{
	    if(strcmpi(m.sn,n)!=0)
	    {
		fwrite(&m,sizeof(m),1,ft);
	    }
	}
	while(fread(&m,sizeof(m),1,fa)==1)
	{
		if(strcmpi(m.sn,n)!=0)
		{
			fwrite(&m,sizeof(m),1,fb);
		}
	}
	fcloseall();
	remove("music.txt");
	rename("abc.txt","music.txt");
	remove("playlist.txt");
	rename("xyz.txt","playlist.txt");
}
void update(char *n)
{
	FILE *fp,*ft,*fa,*fb;
	char c;
	int i,f=0,flag=0;
	fp=fopen("music.txt","r");
	ft=fopen("abc.txt","a+");
	fa=fopen("playlist.txt","r");
	fb=fopen("xyz.txt","a+");
	settextstyle(0,0,1);
	while(fread(&m,sizeof(m),1,fp)==1)
	{
		if(strcmp(m.mn,n)!=0)
		{
			fwrite(&m,sizeof(m),1,ft);
		}
		else if(strcmp(m.mn,n)==0)
			f=1;
	}
	while(fread(&m,sizeof(m),1,fa)==1)
	{
		if(strcmp(m.mn,n)!=0)
		{
			fwrite(&m,sizeof(m),1,fb);
		}
		else
			flag=1;
	}
	if(f==1)
	{
	outtextxy(350,400,"type BACK to main menu");
	outtextxy(350,420,"type EXIT to exit the prog.");
	outtextxy(50,132,"Enter music name :-");
	gotoxy(28,9);
	flushall();
	gets(m.mn);
	if(strlen(m.mn)<50)
	{
		i=0;
		if(m.mn[i]=='\0')
			strcpy(m.mn,"UNKNOWN");
		else if(strcmpi(m.mn,"back")==0)
		{
			menu();
		}
		else if(strcmpi(m.mn,"exit")==0)
		{
			setfillstyle(SOLID_FILL,YELLOW);
			bar(350,400,570,440);
			outtextxy(50,400,"Do you sure to exit the program [y/n]");
			fflush(stdin);
			c=getche();
			if(c=='y')
			{
				outtextxy(200,430,"THANX FOR VISIT...!!!");
				getch();
				closegraph();
			}
			else if(c=='n')
			{
				menu();
			}
			else
			{
				outtextxy(50,430,"Plz enter a valid choice....");
				setfillstyle(SOLID_FILL,YELLOW);
				bar(50,400,500,500);
			}
		}
	}
	else
	{
		outtextxy(50,400,"Limit of music name's size is out of range");
		getch();
		fcloseall();
		remove("abc.txt");
		remove("xyz.txt");
		menu();
	}
	outtextxy(50,164,"Enter album name :-");
	gotoxy(28,11);
	flushall();
	gets(m.an);
	if(strlen(m.an)<50)
	{
		i=0;
		if(m.an[i]=='\0')
			strcpy(m.an,"UNKNOWN");
		else if(strcmpi(m.an,"back")==0)
		{
			menu();
		}
		else if(strcmpi(m.an,"exit")==0)
		{
			setfillstyle(SOLID_FILL,YELLOW);
			bar(350,400,570,440);
			outtextxy(50,400,"Do you sure to exit the program [y/n]");
			fflush(stdin);
			c=getche();
			if(c=='y')
			{
				outtextxy(200,430,"THANX FOR VISIT...!!!");
				getch();
				closegraph();
			}
			else if(c=='n')
			{
				menu();
			}
			else
			{
				outtextxy(50,430,"Plz enter a valid choice....");
				setfillstyle(SOLID_FILL,YELLOW);
				bar(50,400,500,500);
			}
		}
	}
	else
	{
		outtextxy(50,400,"Limit of album name's size is out of range");
		getch();
		fcloseall();
		remove("abc.txt");
		remove("xyz.txt");
		menu();
	}
	outtextxy(50,196,"Enter singer name :-");
	gotoxy(28,13);
	flushall();
	gets(m.sn);
	if(strlen(m.sn)<50)
	{
		i=0;
		if(m.sn[i]=='\0')
			strcpy(m.sn,"UNKNOWN");
		else if(strcmpi(m.sn,"back")==0)
		{
			menu();
		}
		else if(strcmpi(m.sn,"exit")==0)
		{
			setfillstyle(SOLID_FILL,YELLOW);
			bar(350,400,570,440);
			outtextxy(50,400,"Do you sure to exit the program [y/n]");
			fflush(stdin);
			c=getche();
			if(c=='y')
			{
				outtextxy(200,430,"THANX FOR VISIT...!!!");
				getch();
				closegraph();
			}
			else if(c=='n')
			{
				menu();
			}
			else
			{
				outtextxy(50,430,"Plz enter a valid choice....");
				setfillstyle(SOLID_FILL,YELLOW);
				bar(50,400,500,500);
			}
		}
	}
	else
	{
		outtextxy(50,400,"Limit of singer name's size is out of range");
		getch();
		fcloseall();
		remove("abc.txt");
		remove("xyz.txt");
		menu();
	}
	outtextxy(50,228,"Enter music size :-");
	gotoxy(28,15);
	flushall();
	gets(m.size);
	if(strlen(m.size)<50)
	{
		if(strcmpi(m.size,"back")==0)
		{
			menu();
		}
		else if(strcmpi(m.size,"exit")==0)
		{
			setfillstyle(SOLID_FILL,YELLOW);
			bar(350,400,570,440);
			outtextxy(50,400,"Do you sure to exit the program [y/n]");
			fflush(stdin);
			c=getche();
			if(c=='y')
			{
				outtextxy(200,430,"THANX FOR VISIT...!!!");
				getch();
				closegraph();
			}
			else if(c=='n')
			{
				menu();
			}
			else
			{
				outtextxy(50,430,"Plz enter a valid choice....");
				setfillstyle(SOLID_FILL,YELLOW);
				bar(50,400,500,500);
			}
		}
	}
	else
	{
		outtextxy(50,400,"Limit of music name's size is out of range");
		getch();
		fcloseall();
		remove("abc.txt");
		remove("xyz.txt");
		menu();
	}
	fwrite(&m,sizeof(m),1,ft);
	if(flag==1)
		fwrite(&m,sizeof(m),1,fb);
	fcloseall();
	remove("music.txt");
	rename("abc.txt","music.txt");
	remove("playlist.txt");
	rename("xyz.txt","playlist.txt");
	}
	else
	{
		outtextxy(100,300,"This song is not available in music library");
		getch();
	}
}
void change_pass()
{
	FILE *fp,*ft;
	char p1[30],np1[30],np2[30];
	char op[30],ch;
	int i,cnt=0;
	fp=fopen("pass.txt","r");
	ft=fopen("pass1.txt","w");
	cleardevice();
	settextstyle(8,0,1);
	outtextxy(100,50,"CHANGE PASSWORD");
	settextstyle(0,0,1);
	i=0;
	outtextxy(50,118,"Enter your old password : ");
	gotoxy(34,8);
	flushall();
	while(1)
	{
		ch=getch();
		printf("*");
		if(ch=='\r')
		{
			printf("\b \b");
			break;
		}
		if(ch==8)
		{
		     if(i!=0)
		     {
			printf("\b \b\b \b");
			i--;
		     }
		     else
		     {
			printf("\b \b");
		     }
		}
		if(ch!=8)
		{
			p1[i]=ch;
			i++;
			cnt++;
		}
		if(cnt>12)
		{
			outtextxy(250,400,"Limit exceeding");
			delay(500);
		}
	}
	p1[i]='\0';
	fscanf(fp,"%s",gpass);
	if(strcmp(p1,gpass)==0)
	{
		cleardevice();
		outtextxy(50,100,"Enter your new password : ");
		gotoxy(34,7);
		cnt=0;
		i=0;
		while(1)
		{
			ch=getch();
			printf("*");
			if(ch=='\r')
			{
				printf("\b \b");
				break;
			}
			if(ch==8)
			{
			     if(i!=0)
			     {
				printf("\b \b\b \b");
				i--;
			     }
			     else
			     {
				printf("\b \b");
			     }
			}
			if(ch!=8)
			{
				np1[i]=ch;
				i++;
				cnt++;
			}
			if(cnt>12)
			{
				outtextxy(250,400,"Limit exceeding");
				delay(500);
			}
		 }
		 np1[i]='\0';
		outtextxy(50,135,"Renter the password : ");
		gotoxy(30,9);
		cnt=0;
		i=0;
	       while(1)
		{
			ch=getch();
			printf("*");
			if(ch=='\r')
			{
				printf("\b \b");
				break;
			}
			if(ch==8)
			{
			     if(i!=0)
			     {
				printf("\b \b\b \b");
				i--;
			     }
			     else
			     {
				printf("\b \b");
			     }
			}
			if(ch!=8)
			{
				np2[i]=ch;
				i++;
				cnt++;
			}
			if(cnt>12)
			{
				outtextxy(250,400,"Limit exceeding");
				delay(500);
			}
		 }
		 np2[i]='\0';
		if(strcmp(np1,np2)==0)
		{
			fprintf(ft,"%s",np1);
		}
		else
		{
			outtextxy(200,400,"Password does not match");
			fprintf(ft,"%s",gpass);
			getch();
		}
	}
	else
	{
		fprintf(ft,"%s",gpass);
		outtextxy(150,200,"Old password is incorrect");
		outtextxy(100,400,"do u want to renter the password [y/n]");
		ch=getche();
		if(ch=='y')
		{
			change_pass();
		}
		else if(ch=='n')
		{
			menu();
		}
		else
		{
			setfillstyle(SOLID_FILL,YELLOW);
			bar(50,400,500,500);
			outtextxy(200,400,"WRONG CHOICE");
			getch();
		}
	}
	fcloseall();
	remove("pass.txt");
	rename("pass1.txt","pass.txt");
}
void load()
{
	int i,j;
	for(i=0;i<360;i++)
	{
		settextstyle(0,0,1);
		setcolor(RED);
		outtextxy(300,220,"LOADING");
		setcolor(RED);
		circle(280,220,10);
		circle(280,220,9);
		circle(280,220,8);
		for(j=8;j<=10;j++)
		{
			setcolor(YELLOW);
			arc(280,220,80-i,90-i,j);
		}
		delay(10);
		cleardevice();
	}
	setcolor(RED);
}
void wel()
{
	int i,j;
	cleardevice();
	setbkcolor(RED);
	for(i=1;i<=15																																											;i++)
	{
		rectangle((i-1),(i-1),(getmaxx()-(i-1)),(getmaxy()-(i-1)));
		setcolor(i);
	}
	setcolor(1);
	for(i=0;i<15;i++)
	{
		setcolor(i);
		ellipse(300,310,0,180,220,240+i);
		setcolor(YELLOW);
		line(80,310,80,330);
		line(520,310,520,330);
		line(75,300,75,320);
		arc(85,300,110,180,10);
		arc(85,320,180,240,10);
		arc(101,290,90,180,20);
		arc(101,330,180,270,20);
		arc(121,270,90,180,20);
		arc(121,350,180,270,20);
		line(525,300,525,320);
		arc(515,300,0,70,10);
		arc(515,320,300,360,10);
		arc(499,290,0,90,20);
		arc(499,330,270,360,20);
		arc(479,270,0,90,20);
		arc(479,350,270,360,20);
		line(121,250,121,370);
		line(479,250,479,370);
	}
	setcolor(7);
	settextstyle(1,0,5);
	outtextxy(150,250,"MUSIC LIBRARY");
	outtextxy(230,300,"SYSTEM");
	getch();
}