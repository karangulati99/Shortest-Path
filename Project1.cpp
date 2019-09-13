#include<iostream>
#include<cmath>
#include<time.h>
#include <fstream>

using namespace std;

int counter=0;

struct node{
	int x;
	int y;
	node *next;	
};

struct node *start = NULL;

void insert(int a,int b,char ab[10])
{
	fstream st;
	node *temp=new node;
    st.open(ab,ios::app);
    st<<a<<","<<b<<endl; 
	node *newnode=new node;
	newnode->x=a;
	newnode->y=b;
	newnode ->next=NULL;
	    
	if(start==NULL)
	{
		start=temp=newnode;
	}
	else
	{
		temp->next=newnode;
		temp=temp->next;
	}
	 st.close();
}


void display(char ab[10])
{
    char ch,dh,eh;
	fstream st;		
	st.open(ab,ios::in);
	node *temp=start;

	while (!st.eof())
    {
    st >>ch;
	st >>dh;  
    st >>eh; 
    cout << ch <<dh<<eh<<endl; 
    }
    
	st.close();	
}


class chess
{
	public:
	friend void insert(int x,int y,char ab[10]);	

	void king(int ix,int iy,int fx,int fy)
	{	
		chess c2;
		char ab[10]="king.txt";
		cout<<"\nINITIAL POSITION"<<endl;
		cout<<"("<<ix<<","<<iy<<")"<<endl;
		c2.mov(ix,iy);
		insert(ix ,iy,ab);
		cout<<endl;
		while(ix!=fx||iy!=fy)
		{	
			if(ix==fx)
			{
				if(iy<fy)
				{
					iy=iy+1;
				}
				
				else
				{
					iy=iy-1;
				}		
			}
				
			else if(iy==fy)
			{
				if(ix<fx)
				{
					ix=ix+1;
				}
				else
				{
					ix=ix-1;
				}		
			}	
		
			else
			{
				if(ix<fx&&iy<fy)
				{
					ix=ix+1;
					iy=iy+1;
				}
				else if(ix>fx&&iy>fy)
				{
					ix=ix-1;
					iy=iy-1;
				}
				else if(ix<fx&&iy>fy)
				{
					ix=ix+1;
					iy=iy-1;
				}
				else
				{
					ix=ix-1;
					iy=iy+1;
				}			
			}
			counter++;
			cout<<"\nNext Move"<<endl;
			cout<<"("<<ix<<","<<iy<<")"<<endl;
			c2.mov(ix,iy);
			insert(ix,iy,ab);
		}
		cout<<"\nTotal number of moves = "<<counter<<endl;
		cout<<endl;
	}	


	void knight(int ix, int iy, int fx, int fy)
	{
    	chess c5;
    	char ab[19]="knight.txt";
	    cout<<"\nInitial Position"<<endl;
		cout<<"("<<ix<<","<<iy<<")"<<endl;
		c5.mov(ix,iy);
		insert(ix,iy,ab);

		while(ix!=fx||iy!=fy)
		{
			if(ix==fx)
			{
				if(iy<fy)
				{
					ix=ix+2;
					if(ix>8)
					ix=ix-4;
				
					iy=iy+1;
					if(iy>8)
					iy=iy-2;
				}	
				else
				{
					ix=ix-2;
					if(ix<1)
					ix=ix+4;
				
					iy=iy-1;
					if(iy<1)
					iy=iy+2;
				}
				cout<<endl;
			}
		
			else if(iy==fy)
			{
				if(ix<fx)
				{
					iy=iy+2;
					if(iy>8)
					iy=iy-4;
				
					ix=ix+1;
					if(ix>8)
					ix=ix-2;
				}
			
				else
				{
					iy=iy-2;
					if(ix<1)
					iy=iy+4;
					
					ix=ix-1;
					if(ix<1)
					ix=ix+2;
				}
				cout<<endl;
			}
		
			else
			{
				if(ix<fx&&iy<fy)
				{
					ix=ix+2;
					if(ix>8)
					ix=ix-4;
					
					iy=iy+1;
					if(iy>8)
					iy=iy-2;
				}
			
				else if(ix>fx&&iy>fy)
				{
					ix=ix-2;
					if(ix<1)
					ix=ix+4;
					
					iy=iy-1;
					if(iy<1)
					iy=iy+2;
				}
				
				else if(ix<fx&&iy>fy)
				{
					ix=ix+2;
					if(ix>8)
					ix=ix-4;
					
					iy=iy-1;
					if(iy<1)
					iy=iy+2;
				}
			
				else
				{
					ix=ix-2;
					if(ix<1)
					ix=ix+4;
					
					iy=iy+1;
					if(iy>8)
					iy=iy-2;
				}
				cout<<endl;
			}
			counter++;
			cout<<"\nNext Move"<<endl;
			cout<<"("<<ix<<","<<iy<<")"<<endl;
			c5.mov(ix,iy);
			insert(ix,iy,ab);
		}
		cout<<"\nTotal number of moves = "<<counter<<endl;
		cout<<endl;
	}

	void bishop(int ix,int iy,int fx,int fy)
	{
		chess c4;
		char ab[19]="bishop.txt";
		int flag=-2,flag1=-2;
	
		if(ix%2==0&&iy%2==0)
		{
			flag=1;
		}
	
		else if(ix%2==1&&iy%2==1)
		{
			flag=1;
		}

		else if(ix%2==0&&iy%2==1)
		{
			flag=0;
		}
	
		else if(ix%2==1&&iy%2==0)
		{
		flag=0;
		}

		if(fx%2==0&&fy%2==0)
		{
			flag1=1;
		}
	
		else if(fx%2==1&&fy%2==1)
		{
			flag1=1;
		}

		else if(fx%2==0&&fy%2==1)
		{
			flag1=0;
		}
	
		else if(fx%2==1&&fy%2==0)
		{
			flag1=0;
		}
	
		if(flag!=flag1)
		{
			cout<<"kindly enter the valid intial and final point for bishop"<<endl;
			return ;
		}
		
		else
		{
			if(flag*flag1==0)
			{
				cout<<"you have chosen a black bishop"<<endl;
			}
		
			else
			cout<<"you have chosen a white bishop"<<endl;
		}
		
		cout<<"Next Move"<<endl;
		cout<<"("<<ix<<","<<iy<<")"<<endl;
		c4.mov(ix,iy);
		insert(ix ,iy,ab);
		cout<<endl;
		
		if(abs(ix-fx)==abs(iy-fy))
		{
			cout<<"Next Move"<<endl;
			cout<<"("<<fx<<","<<fy<<")"<<endl;
			c4.mov(fx,fy);
		}
		
		else if(abs(ix-fx)!=abs(iy-fy))
		{
			if(ix<fx&&iy<fy)
			{
				for(int i=ix;i<8;i++)
				{
					if(abs(ix-fx)==abs(iy-fy))
					{
						cout<<"Next Move"<<endl;
						cout<<"("<<ix<<","<<iy<<")"<<endl;
						c4.mov(ix,iy);
						insert(ix ,iy,ab);
						cout<<endl;
					    cout<<endl;
					    cout<<"Next Move"<<endl;
					    cout<<"("<<fx<<","<<fy<<")"<<endl;
						c4.mov(fx,fy);
						insert(fx ,fy,ab);
						break;
					}
					
				ix++;
				iy++;
				}
			}
				
			else if(ix<fx&&iy>fy)
			{
				for(int i=ix;i<8;i++)
				{
					if(abs(ix-fx)==abs(iy-fy))
					{
						cout<<"Next Move"<<endl;
						cout<<"("<<ix<<","<<iy<<")"<<endl;
						c4.mov(ix,iy);
						insert(ix ,iy,ab);
						cout<<endl;
						cout<<endl;
						cout<<"Next Move"<<endl;
						cout<<"("<<fx<<","<<fy<<")"<<endl;
						c4.mov(fx,fy);
						insert(fx ,fy,ab);
						break;
					}
					ix++;
					iy++;
				}
			}
			
			else if(iy<fy&&ix>fx)
			{
				for(int i=iy;i<8;i++)
				{
						if(abs(ix-fx)==abs(iy-fy))
					{
						cout<<"Next Move"<<endl;
						cout<<"("<<ix<<","<<iy<<")"<<endl;
						c4.mov(ix,iy);
						insert(ix ,iy,ab);
						cout<<endl;
						cout<<endl;
						cout<<"Next Move"<<endl;
						cout<<"("<<fx<<","<<fy<<")"<<endl;
						c4.mov(fx,fy);
						insert(fx ,fy,ab);
						break;
					}
					iy++;
					ix++;
				}
			}
		}
	}


	void pawn(int ix,int iy,int fx,int fy)
	{
		chess c3;
		char ab[10]="pawn.txt";
		cout<<"\nInitial Position"<<endl;
		cout<<"("<<ix<<","<<iy<<")"<<endl;
		c3.mov(ix,iy);
		insert(ix ,iy,ab);
		cout<<endl;
			
		if(ix!=fx)
		{
		cout<<"\nInvalid Moves for Pawn\n";
		return ;
		} 
	
		int i;
	
		if(iy<fy)
		{
			cout<<"\nYou are playing White\n";	
			if(iy==1)
			{
				cout<<"Invalid Position for Pawn\n";
				return ;
			}
		   	else if(ix==fx)
			{   
				if(iy==2&&fy!=3)
				{
					char st;
					cout<<"\nDo You want move to "<<ix<<",4\n";
					cout<<"Enter Y or y for Yes\n";
					cin>>st;
					if(st=='Y'||st=='y')
					{
						for(i=iy+2;i<=fy;i++)
			     	   {	
							cout<<"\nNext Move"<<endl;
							cout<<"("<<fx<<","<<i<<")"<<endl;
   			 			    c3.mov(fx,i);
    					    cout<<endl;
							insert(fx ,i,ab);
							counter++;
						}
					}
					else
					{
    			   		for(i=iy+1;i<=fy;i++)
       					{	
							cout<<"\nNext Move"<<endl;
							cout<<"("<<fx<<","<<i<<")"<<endl;
    		   				c3.mov(fx,i);
  	 						cout<<endl;
							insert(fx ,i,ab);
							counter++;
						}
					}
				}
				else
				{
    		   		for(i=iy+1;i<=fy;i++)
       				{	
						cout<<"\nNext Move"<<endl;
						cout<<"("<<fx<<","<<i<<")"<<endl;
    	   				c3.mov(fx,i);
  	 					cout<<endl;
						insert(fx ,i,ab);
						counter++;
					}
				}
    		}
		}	
	
		else if(iy>fy)
		{
			cout<<"\nYou are playing Black\n";	
		
			if(iy==8)
			{
				cout<<"Invalid Position for Pawn\n";
				return ;
			}
		
	    	else if(ix==fx)
			{  	 
				if(iy==7&&fy!=6)
				{
					char st;
					cout<<"\nDo You want move to "<<ix<<",5\n";
					cout<<"Enter Y or y for Yes\n";
					cin>>st;
					if(st=='Y'||st=='y')
					{
						for(i=iy-2;i>=fy;i--)
	   				  	{	
							cout<<"\nNext Move"<<endl;
							cout<<"("<<fx<<","<<i<<")"<<endl;
    				   		c3.mov(fx,i);
    				    	cout<<endl;
							insert(fx ,i,ab);
							counter++;
						}
					}
					else
					{
    	   	 			for(i=iy-1;i>=fy;i--)
    					{		
							cout<<"\nNext Move"<<endl;
							cout<<"("<<fx<<","<<i<<")"<<endl;
    			   			c3.mov(fx,i);
      						cout<<endl;	
							insert(fx ,i,ab);
							counter++;
						}
    				}					
				}
				else
				{
    	   	 		for(i=iy-1;i>=fy;i--)
    				{		
						cout<<"\nNext Move"<<endl;
						cout<<"("<<fx<<","<<i<<")"<<endl;
    			   		c3.mov(fx,i);
      					cout<<endl;	
						insert(fx ,i,ab);
						counter++;
					}
    			}
    		}
		}
		cout<<"\nTotal number of moves = "<<counter<<endl;
		cout<<endl;   
	}


	void queen(int ix,int iy,int fx,int fy)
	{
   		chess c3;
   		char ab[12]="queen.txt";
   		cout<<"\nInitial Position"<<endl;
		cout<<"("<<ix<<","<<iy<<")"<<endl;
		c3.mov(ix,iy);
		insert(ix,iy,ab);
    	
		if(ix==fx||iy==fy||abs(fx-ix)==abs(fy-iy))
		{
        	cout<<"\nNext Move"<<endl;
			cout<<"("<<fx<<","<<fy<<")"<<endl;
        	c3.mov(fx,fy);
        	insert(fx ,fy,ab);
       		cout<<"\nTotal number of moves = 1"<<endl;
			cout<<endl;
    	}
   		else
		{
   			cout<<"\nNext Move"<<endl;
			cout<<"("<<fx<<","<<iy<<")"<<endl;
    		c3.mov(fx,iy);
      		insert(fx ,iy,ab);
      		cout<<"\nNext Move"<<endl;
			cout<<"("<<fx<<","<<fy<<")"<<endl;
        	c3.mov(fx,fy);
        	insert(fx ,fy,ab);
        	cout<<"\nTotal number of moves = 2"<<endl;
			cout<<endl;
		}
	}


	void rook(int ix,int iy,int fx,int fy)
	{
		char ab[10]="rook.txt";
		chess c3;
		cout<<"\nInitial Position"<<endl;
		cout<<"("<<ix<<","<<iy<<")"<<endl;
		c3.mov(ix,iy);
		insert(ix,iy,ab);
	    if(ix==fx)
		{
   		    cout<<"\nNext Move"<<endl;
			cout<<"("<<fx<<","<<fy<<")"<<endl;
       		c3.mov(fx,fy);
       		insert(fx ,fy,ab);
       		cout<<"\nTotal number of moves = 1"<<endl;
			cout<<endl;
    	}
    
    	else if(iy==fy)
    	{
    		cout<<"\nNext Move"<<endl;
			cout<<"("<<fx<<","<<iy<<")"<<endl;
 			c3.mov(fx,iy);
 			insert(fx ,iy,ab);
 			cout<<"\nTotal number of moves = 1"<<endl;
			cout<<endl;
		}
    
   		else
		{
    		cout<<"\nNext Move"<<endl;
			cout<<"("<<fx<<","<<iy<<")"<<endl;
    	   	c3.mov(fx,iy);
       		insert(fx ,iy,ab);
    		cout<<"\nNext Move"<<endl;
			cout<<"("<<fx<<","<<fy<<")"<<endl;
       		c3.mov(fx,fy);
    	   	insert(fx ,fy,ab);
  			cout<<"\nTotal number of moves = 2"<<endl;
			cout<<endl;	
		}
	
	}


	void display(char ab[10])
	{
    	char ch,dh,eh;
	    fstream st;
			
		st.open(ab,ios::in);
		node *temp=start;
		
		while (!st.eof())
        {
            st >>ch;
			st >>dh;  
            st >>eh;  
              
            cout << ch <<dh<<eh<<endl; 
        }
        
		st.close();
	}
		

	void mov(int x,int y)
	{
		int a[10][10];
		clock_t ticks1, ticks2;
		int i,j;
		for(int i=1;i<9;i++)
		{
			for(int j=1;j<9;j++)
			{
				a[i][j]=0;
			}	
		}
		a[abs(y-9)][x]=1;	

		for(int i=1;i<9;i++)
		{
			cout<<endl;
			for(int j=1;j<9;j++)
			{	
				cout<<"\t"<<a[i][j]<<"";
			}
			cout<<endl;
			cout<<endl;
		}
	
		ticks1=clock();
		ticks2=ticks1;
		while((ticks2/CLOCKS_PER_SEC-ticks1/CLOCKS_PER_SEC)<4.25)
		ticks2=clock();
	}
	
	
	int trav(int ix,int iy,int fx,int fy)
	{	
		if((ix>0&&iy>0&&ix<9&&iy<9)&&(fx>0&&fy>0&&fx<9&&fy<9))
		return 1;
		else
		return 0;
	}
	
	
	void all()
	{
		int ch;
		chess c9;
		char aa[15]="king.txt";
		char ab[15]="queen.txt";
		
		char ac[15]="bishop.txt";
		char ad[15]="rook.txt";
		char ae[15]="knight.txt";
		char af[15]="pawn.txt";
		do
		{
			cout<<"Moves\n";
			cout<<"1) King \n2) Queen 3) Bishop \n4) Rook \n5) Knight \n6) Pawn"<<endl;
			cin>>ch;
			switch(ch)
			{
				case 1: c9.display(aa);
				break;
				case 2: c9.display(ab);
				break;
				case 3: c9.display(ac);
				break;
				case 4: c9.display(ad);
				break;
				case 5: c9.display(ae);
				break;
				case 6: c9.display(af);
				break;
				case 7: return ;
				break;
				default:cout<<"kindly enter the valid option"<<endl;
			}	
		}while(true);
	}
};


int main()
{
	
	chess c1;
	ax:
	int ch,a,b,c,d;
	char sup,pos;
	cout<<"\t\t\t\t\t\t\t\t***************************** CHESS TRAVERSAL ALGORITHM *******************************"<<endl;
	cout<<endl;
	cout<<endl;
	
	cout<<"\t\t\t\t Enter the initial x co-ordinate :"<<"\t";
	cin>>a;
	cout<<endl;
	cout<<"\t\t\t\t Enter the initial y co-ordinate :"<<"\t";
	cin>>b;
	cout<<endl;
	cout<<"\t\t\t\t Initial position is:"<<"\t";
	cout<<"("<<a<<","<<b<<")"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"\t\t\t Now"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t Enter the final x co-ordinate :"<<"\t";
	cin>>c;
	cout<<endl;
	cout<<"\t\t\t\t Enter the final y co-ordinate :"<<"\t";
	cin>>d;
	cout<<endl;
	cout<<"\t\t\t\t Final position is:"<<"\t";
	cout<<"("<<c<<","<<d<<")"<<endl;
	cout<<endl;
	cout<<endl;
	int ix,iy,fx,fy;

	if(c1.trav(a,b,c,d))
	{	
		cout<<"\t\t\t Valid initial and final positions."<<"\t";
		cout<<endl;
		cout<<endl;
		cout<<"\t\t\t So,Go ahead! Please start the movement."<<"\t";
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;	
	}
	
	else
	{	
		cout<<"\t\t\t Please enter from the valid position"<<"\t";
		cout<<endl;
		cout<<endl;
		goto ax;
	}	
	
	do
	{	
		cout<<"\t\t\t\t\t\t What do you want to choose?"<<endl;
		cout<<endl;
		cout<<"\t\t\t\t\t 1.King \n\t\t\t\t\t 2.Pawn\n\t\t\t\t\t 3.Rook\n\t\t\t\t\t 4.Queen\n\t\t\t\t\t 5.Bishop\n\t\t\t\t\t 6.Knight\n\t\t\t\t\t 7.Display all the moves\n\t\t\t\t\t 8.Exit"<<endl;
		cout<<endl;
	
		cin>>ch;
   
		switch(ch)
		{	
			case 1:
				cout<<"\t\t\t You have chosen king"<<"\t";	
				cout<<endl;
				c1.king(a,b,c,d);
				break;
				
			case 2:
				cout<<"\t\t\t You have chosen pawn"<<"\t";
				c1.pawn(a,b,c,d);
				break;
			
			case 3:
				cout<<"\t\t\t You have chosen rook"<<"\t";
				c1.rook(a,b,c,d);
				break;
		
			case 4:
				cout<<"\t\t\t You have chosen queen"<<"\t";
				c1.queen(a,b,c,d);
				break;
			
			case 5:
				cout<<"\t\t\t You have chosen bishop"<<"\t";
				c1.bishop(a,b,c,d); 
				break;
	
			case 6:
				cout<<"\t\t\t You have chosen knight"<<"\t";
				c1.knight(a,b,c,d);
				break;
		
			case 7:
				cout<<"\t\t\t You want to display all the moves"<<"\t";
				c1.all();
				break;
	
			case 8:
				exit(0);	
				
			default: cout<<"Please choose the correct option"<<endl;
		}
		
		cout<<"Do you wish to Continue??\n";
		cout<<"If Yes Enter Y or y\n";
		cin>>sup;
		if(sup=='y'||sup=='Y')
		{
			cout<<"Do you want same postions\n";
			cout<<"If Yes Enter Y or y\n";
			cin>>pos;
			if(pos=='y'||pos=='Y')
			{
				a=a;
				b=b;
				c=c;
				d=d;
			}
			else
			{
				cout<<"\t\t\t\t Enter the initial x co-ordinate :"<<"\t";
				cin>>a;
				cout<<endl;
				cout<<"\t\t\t\t Enter the initial y co-ordinate :"<<"\t";
				cin>>b;	
				cout<<endl;
				cout<<"\t\t\t\t Initial position is:"<<"\t";	
				cout<<"("<<a<<","<<b<<")"<<endl;		
				cout<<endl;
				cout<<endl;		
				cout<<"\t\t\t Now"<<endl;
				cout<<endl;
				cout<<"\t\t\t\t Enter the final x co-ordinate :"<<"\t";	
				cin>>c;	
				cout<<endl;
				cout<<"\t\t\t\t Enter the final y co-ordinate :"<<"\t";		
				cin>>d;
				cout<<endl;
				cout<<"\t\t\t\t Final position is:"<<"\t";
				cout<<"("<<c<<","<<d<<")"<<endl;
				cout<<endl;
				cout<<endl;
				int ix,iy,fx,fy;

				if(c1.trav(a,b,c,d))
				{	
					cout<<"\t\t\t Valid initial and final positions."<<"\t";
					cout<<endl;
					cout<<endl;
					cout<<"\t\t\t So,Go ahead! Please start the movement."<<"\t";
					cout<<endl;
					cout<<endl;
					cout<<endl;
					cout<<endl;	
				}
	
				else
				{	
					cout<<"\t\t\t Please enter from the valid position"<<"\t";
					cout<<endl;
					cout<<endl;
					goto ax;
				}	
			}
		}	
	}while(sup == 'Y' || sup == 'y');
}
