#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;

char s[20];
 int high__score=0;
void show_loading()
{
    char s[30]="Loading...";
    setcolor(WHITE);
    //rectangle(550+25,280,700+25,340);
    rectangle(300+25,280,450+25,300);

    for(int i=0;i<148;i++)
    {
        setcolor(GREEN);
        line(301+i+25,281,301+i+25,299);
        setcolor(WHITE);
        outtextxy(350,315,s);
        delay(10);
    }

}
void show_help()
{
    cleardevice();
    setcolor(WHITE);
    readimagefile("7.jpg.jpg",240,50,480,250);
    outtextxy(280,255,"Developer : Bondhon Das");
    outtextxy(280,270,"Student ID: 20CSE016");
    setbkcolor(GREEN);
    settextstyle(4, HORIZ_DIR, 1);
    outtextxy(40,20,"Arrow Master: Aim,Shoot and Conquer the High Score");
    setbkcolor(BLACK);
    settextstyle(9, HORIZ_DIR,1);

    rectangle(150,350,620,590);
    outtextxy(300, 355, "Help Information:");
    outtextxy(160, 370, "- Use any keys to control the bow");
    outtextxy(160, 400, "- Press any key to shoot the arrow");
    outtextxy(160, 430, "- Hit the objects to gain points");
    outtextxy(160, 460, "- Avoid missing the objects to preserve lives");
    setcolor(YELLOW);
    outtextxy(160, 490, "- Press 'P' to Play The game");
    setcolor(RED);
    outtextxy(160, 520, "- Press 'Q' to quit the game");
    setcolor(YELLOW);
    outtextxy(160, 550, "Back to Game");
    //settextstyle(DEFAULT_FONT,USER_CHAR_SIZE, 0);
}
void set_score()
{
    setcolor(WHITE);
    outtextxy(42,35,"Score            : ");
    setcolor(WHITE);
    outtextxy(42,55,"Last point    : ");
    setcolor(WHITE);
    outtextxy(42,75,"High Score  : ");
    outtextxy(42,95,"Lives            : ");
}
void point_lives(int n,int p,int m)
{

    char  s[33];
    sprintf(s,"%d",n);
    char ss[33];
    sprintf(ss,"%d",m);
    char sss[33];
    sprintf(sss,"%d",p);

    setcolor(WHITE);
    outtextxy(200,35,s);
    setcolor(GREEN);
    outtextxy(200,55,ss);

    setcolor(RED);
    outtextxy(200,95,sss);


}
void high_score(int hs)
{
    char h_s[20];
    sprintf(h_s,"%d",hs);
    setcolor(WHITE);
    outtextxy(200,75,h_s);

}

int  game_part(int b=10)
{
    int page=0,k=0;
    int point=0,lives=5,p=0,h_score=0;
    bool gameplay=true;
    while(true)
    {
        setactivepage(page);
        cleardevice();
        setvisualpage(1-page);
        set_score();
        point_lives(point,lives,p);
        high_score(high__score);
        //bow
        arc(39,245,-70,70,50);
        arc(40,245,-70,70,50);
        arc(38,245,-70,70,50);
        arc(41,245,-70,70,50);
        line(56,200,56-b,246);
        line(56-b,246,56,292);
        //arrow
        line(56-b,246,120-b,246);
        //arrow triangle
        line(116-b,242,120-b,246);
        line(116-b,250,120-b,246);
        line(116-b,242,116-b,250);

        int mn=22,mx=450;
        int page0=0,flag=1,pp=0,gameplay=1;
        for(int i=mn;;)
        {
            setactivepage(page0);
            cleardevice();
            setvisualpage(1-page0);
            set_score();
            point_lives(point,lives,p);
            high_score(high__score);

            setcolor(YELLOW);
            //bow
            setcolor(YELLOW);
            //bow
            arc(39,245,-70,70,50);
            arc(40,245,-70,70,50);
            arc(38,245,-70,70,50);
            arc(41,245,-70,70,50);
            line(56,200,56-b,246);
            line(56-b,246,56,292);
            //arrow
            line(56-b,246,120-b,246);
            //arrow triangle
            line(116-b,242,120-b,246);
            line(116-b,250,120-b,246);
            line(116-b,242,116-b,250);
            if(i<=mx&&flag==1)
            {

                if(i==mx)flag=0;
                i++;
                //object
                line(713,i,713,i+120);
                line(714,i,714,i+120);
                setfillstyle(SOLID_FILL,YELLOW);
                arc(713,i+60,90,270,20);
                arc(714,i+60,91,271,20);
                floodfill(707,i+58,YELLOW);
                if(kbhit())
                {
                int page1=0 ,f=1,arrow_hit=1;
                for(int j=1;j<=getmaxx();j++)
                  {

                    setactivepage(page1);
                    cleardevice();
                    setvisualpage(1-page1);
                    set_score();
                    point_lives(point,lives,p);
                    high_score(high__score);


                    //bow
                    setcolor(YELLOW);
                    arc(39,245,-70,70,50);
                    arc(40,245,-70,70,50);
                    arc(38,245,-70,70,50);
                    arc(38,245,-70,70,50);
                    arc(41,245,-70,70,50);
                    line(56,200,56,246);
                    line(56,246,56,292);
                    //arrow
                    line(56+j,246,120+j,246);
                    //arrow triangle
                    line(116+j,242,120+j,246);
                    line(116+j,250,120+j,246);
                    line(116+j,242,116+j,250);

                    if(i<=mx&&f==1)
                    {
                        //object

                        if(i==mx)f=0;
                        i++;
                        setcolor(YELLOW);
                        line(713,i,713,i+120);
                        line(714,i,714,i+120);
                        setfillstyle(SOLID_FILL,YELLOW);
                        arc(713,i+60,90,270,20);
                        arc(714,i+60,91,271,20);
                        floodfill(707,i+58,YELLOW);

                    }
                   if(i>=mn&&f==0)
                    {

                        //object
                        if(i==mn)f=1;
                        i--;
                        setcolor(YELLOW);
                        line(713,i,713,i+120);
                        line(714,i,714,i+120);
                        setfillstyle(SOLID_FILL,YELLOW);
                        arc(713,i+60,90,270,20);
                        arc(714,i+60,91,271,20);
                        floodfill(707,i+58,YELLOW);
                    }
                    if((120+j>=720&&120+j<=730)&& ((i+60>=188&&i+60<=306)) )
                    {
                        Beep(333,444);
                         p=0;
                        if(i+60>=226&&i+60<=266)
                        point+=5,p=5;
                        else if(i+60>=188&&i+60<225)
                        point+=3,p=3;
                        else point+=2,p=2;

                        pp=1;
                        arrow_hit=0;
                        //bow
                        setcolor(WHITE);

                        high_score(high__score);
                        setcolor(YELLOW);
                        arc(39,245,-70,70,50);
                        arc(40,245,-70,70,50);
                        arc(38,245,-70,70,50);
                        arc(38,245,-70,70,50);
                        arc(41,245,-70,70,50);
                        line(56,200,56,246);
                        line(56,246,56,292);
                        //arrow
                        line(56+j,246,120+j,246);
                        //arrow triangle
                        line(116+j,242,120+j,246);
                        line(116+j,250,120+j,246);
                        line(116+j,242,116+j,250);
                        //object
                        setcolor(YELLOW);
                        line(713,i,713,i+120);
                        line(714,i,714,i+120);
                        setfillstyle(SOLID_FILL,YELLOW);
                        arc(713,i+60,90,270,20);
                        arc(714,i+60,91,271,20);
                        floodfill(707,i+58,YELLOW);

                        delay(1000);

                        break;

                    }
                    if(120+j==770)
                        lives--;
                    if(lives<=0)
                    {
                        point_lives(point,lives,p);
                        return point;

                    }

                    delay(.199);
                    page1=1-page1;
                    }
               getch();
                }
            }
            else if(i>=mn&&flag==0)
            {
                if(i==mn)flag=1;i--;
                   //object
                line(713,i,713,i+120);
                line(714,i,714,i+120);
                setfillstyle(SOLID_FILL,YELLOW);
                arc(713,i+60,90,270,20);
                arc(714,i+60,91,271,20);
                floodfill(707,i+58,YELLOW);
                if(kbhit())
                {
                int page1=0,f=1,arrow_hit=1;
                for(int j=1;j<=getmaxx();j++)
                  {

                    setactivepage(page1);
                    cleardevice();
                    setvisualpage(1-page1);
                    set_score();
                    point_lives(point,lives,p);
                    high_score(high__score);



                    //bow
                    setcolor(YELLOW);
                    arc(39,245,-70,70,50);
                    arc(40,245,-70,70,50);
                    arc(38,245,-70,70,50);
                    arc(38,245,-70,70,50);
                    arc(41,245,-70,70,50);
                    line(56,200,56,246);
                    line(56,246,56,292);
                    //arrow
                    line(56+j,246,120+j,246);
                    //arrow triangle
                    line(116+j,242,120+j,246);
                    line(116+j,250,120+j,246);
                    line(116+j,242,116+j,250);

                    if(i<=mx&&f==1)
                    {
                        //object

                        if(i==mx)f=0;
                        i++;
                        setcolor(YELLOW);
                        line(713,i,713,i+120);
                        line(714,i,714,i+120);
                        setfillstyle(SOLID_FILL,YELLOW);
                        arc(713,i+60,90,270,20);
                        arc(714,i+60,91,271,20);
                        floodfill(707,i+58,YELLOW);

                    }
                   if(i>=mn&&f==0)
                    {

                        //object
                        if(i==mn)f=1;
                        i--;
                        setcolor(YELLOW);
                        line(713,i,713,i+120);
                        line(714,i,714,i+120);
                        setfillstyle(SOLID_FILL,YELLOW);
                        arc(713,i+60,90,270,20);
                        arc(714,i+60,91,271,20);
                        floodfill(707,i+58,YELLOW);
                    }

                   if((120+j>=720&&120+j<=730)&& ((i+60>=188&&i+60<=306)) )
                    {
                        Beep(333,444);
                        int p=0;
                        if(i+60>=226&&i+60<=266)
                        point+=5,p=5;
                        else if(i+60>=188&&i+60<225)
                        point+=3,p=3;
                        else point+=2,p=2;
                        pp=1;
                        arrow_hit=0;
                        //bow
                        setcolor(YELLOW);
                        arc(39,245,-70,70,50);
                        arc(40,245,-70,70,50);
                        arc(38,245,-70,70,50);
                        arc(38,245,-70,70,50);
                        arc(41,245,-70,70,50);
                        line(56,200,56,246);
                        line(56,246,56,292);
                        //arrow
                        line(56+j,246,120+j,246);
                        //arrow triangle
                        line(116+j,242,120+j,246);
                        line(116+j,250,120+j,246);
                        line(116+j,242,116+j,250);
                        //object
                        setcolor(RED);
                        line(713,i,713,i+120);
                        line(714,i,714,i+120);
                        setfillstyle(SOLID_FILL,YELLOW);
                        arc(713,i+60,90,270,20);
                        arc(714,i+60,91,271,20);
                        floodfill(707,i+58,YELLOW);

                        delay(1000);
                        page1=1-page1;
                        break;
                    }

                    if(120+j==770)
                    lives--;

                    if(lives<=0)
                    {
                       point_lives(point,lives,p);
                       return point;

                    }
                    delay(.199);
                    page1=1-page1;
                  }
                getch();
                }
            }

         page0=1-page0;

        }



        page=1-page;
    }

}
int main()
{
    initwindow(800,600,"BONDHON");
    FILE *file;
    file=fopen("score.txt","r+");
    fscanf(file,"%d",&high__score);
    fclose(file);
    file=fopen("score.txt","w");
    show_help();
    int b=10;
    int page=0;char p;
         cin>>p;
    if(p=='P'||p=='p')
    {
        cleardevice();
        show_loading();
         cleardevice();
         //bow
        arc(39,245,-70,70,50);
        arc(40,245,-70,70,50);
        arc(38,245,-70,70,50);
        arc(41,245,-70,70,50);
        line(56,200,56-b,246);
        line(56-b,246,56,292);
        //arrow
        line(56-b,246,120-b,246);
        //arrow triangle
        line(116-b,242,120-b,246);
        line(116-b,250,120-b,246);
        line(116-b,242,116-b,250);
        int result=game_part();
        high__score=max(result,high__score);
        high_score(high__score);
        fprintf(file,"%d",high__score);

        fclose(file);

    }
    else if(p=='Q'||p=='q')
    {
        outtextxy(260,290,"You Quit the Game");
        setcolor(RED);
        outtextxy(260,310,"Press anny key to EXIT");
    }

    cleardevice();
    show_help();
    delay(100000000);
    getch();
    closegraph();
}


