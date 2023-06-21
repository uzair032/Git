#include<iostream>
using namespace std;
struct pen
{
	int qty;
	char *color;
	pen *nptr;
};
pen *fptr=NULL;
int main()
{
	int option,opt1,opt3,opt2;
	char s;
	while(1)
	{
		cout<<"Select one of the options\n1.Add pen\n2.Sell pen\n3.Display stock\n";
		cin>>option;
		switch(option)
		{
			case 1:
				{	
					        pen *ptr;
							ptr=new pen;
							cout<<"Select from the following options\n1.Add Aqua\n2.Add Blue\n3.Add Green\n4.Add red\n";
							cin>>opt1;
							cout<<endl;
			                if(opt1>=5)
			                {
			                	cout<<"Invalid entry"<<endl;
			                	break;
							}
							
							if(opt1==1)
							{
							ptr->color="Aqua";
							ptr->qty=1;
						    }
							else if(opt1==2)
							{
							ptr->color="Blue";
							ptr->qty=2;
							}
							else if(opt1==3)
							{
							ptr->color="Green";
							ptr->qty=3;
							}
							else if(opt1==4)
							{
							ptr->color="Red";
							ptr->qty=4;
							}
							if(fptr==NULL)
							{
								ptr->nptr=NULL;
								fptr=ptr;
							}
							else
							{
								pen *currentptr=fptr;
								while(currentptr->nptr!=NULL)
								{
									currentptr=currentptr->nptr;
								}
								ptr->nptr=NULL; 
                                currentptr->nptr=ptr; 
							}
							break;
					}
					case 3:
						{
							cout<<"Following is the stock:"<<endl;
							pen *currentptr=fptr;
							while(currentptr!=NULL)
							{
								if(currentptr->qty!=0)
								{
								cout<<"Color: "<<currentptr->color;
								cout<<endl;
							    }
								currentptr=currentptr->nptr;
							}
							break;
						}
					case 2:
						{
							cout<<"Select from the following options\n1.Sell Aqua\n2.Sell Blue\n3.Sell Green\n4.Sell red\n";
							cin>>opt2;
							cout<<endl;
							pen *currentptr=fptr;
							if(opt2>=5)
							{
								cout<<"No such option"<<endl;
								break;
							}
							while(currentptr!=NULL)
							{
								if(opt2==currentptr->qty)
								{
									currentptr->qty=0;
									cout<<"SOLD"<<endl;
							    }
							    currentptr=currentptr->nptr;
						    }
						    break;
					    }
		    }
		    cout<<"Press A to continue and B to exit\n";
		    cin>>s;
		    system("CLS");
		    if(s=='A')
		    continue;
		    else if(s=='B')
		    break;
	}
	return 0;
}
