bool poss(int board[][9],int cx,int cy,int x)
{
  for(int i=0;i<9;i++)
  {
    if(board[cx][i]==x)
    {
      return false;
    }
  }
  
  for(int j=0;j<9;j++)
  {
    if(board[j][cy]==x)
    {
      return false;
    }
  }
  
  int gr = (cx/3)*3;
  int gc = (cy/3)*3;
  for(int i = gr;i<gr+3;i++)
  {
    for(int j = gc;j<gc+3;j++)
    {
      	if(board[i][j]==x)
        {
          return false;
        }
    }
  }
  return true;
}

bool helper(int board[][9],int cx,int cy)
{
  if(cx>8)return true; 
  if(board[cx][cy]!=0)
  {
    if(cy==8)
    {
      return helper(board,cx+1,0);
    }
    
    else return helper(board,cx,cy+1);
  }
  
  bool nxt=false;
  for(int i=1;i<=9;i++)
  {
    if(poss(board,cx,cy,i))
    {
      	board[cx][cy]=i;
      	if(cy==8)
    	{
      		nxt = helper(board,cx+1,0);
    	}
    
    	else nxt = helper(board,cx,cy+1);
    }
    if(nxt)return nxt;
    board[cx][cy]=0;
  }
  return false;
}

bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
  
  	return helper(board,0,0);
}
