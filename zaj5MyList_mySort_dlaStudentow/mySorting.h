using namespace std;

template <typename T, size_t N>
void mySort(T (&arr)[N])
{
    for (int i = 0; i < N; i++)
	{
		int max = i;
		for (int j = i + 1; j < N; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
            T temp = arr[max];
            arr[max] = arr[i];
            arr[i] = temp;
		}
	}
}

template<typename T>
void mySort(vector<T> arr)
{
    sort(arr.begin(), arr.end());
}

template<typename T>
void mySort(MyList<T> arr)
{
	unique_ptr<MyList::Node> curr = arr.begin(),index=NULL;
    
	while(curr != NULL)
	{
		index = curr->next; 
		while(index != NULL)
		{
			if(curr->data > index->data)
			{
				T temp = curr->data;  
				curr.data = index->data;  
				index->data = temp; 
			}
			index = index->next; 
			curr = current->next;  
		}
	}       
}

struct Cmp{
	static bool eq (unsigned char a,unsigned char b){return a==b;}
	static bool lt (unsigned char a,unsigned char b){return a<b;}
}

/*
struct Cmp_insensitive{
	static bool eq (unsigned char a,unsigned char b){return tolower(a)==tolower(b);}
	static bool lt (unsigned char a,unsigned char b){return tolower(a)<tolower(b);}
}
*/

template<class C=Cmp>
int cmp (const char[] s1,const char[] s2)
{

	for (unsigned i=0;i<strlen(s1) && i<strlen(s2);i++)
		if(!C::eq(s1[i],s2[i]))return C::lt(s1[i],s2[i])?-1:1;
	return (int) (strlen(s1) - strlen(s2));
}


template<typename T, size_t N>
void mySort(char arr[][N])
{
	for (int i = 0; i < N; i++)
	{
		int max = i;
		for (int j = i + 1; j < N; j++)
		{
				
			if (cmp(arr[][max], arr[][j] )<0)
			{
				max = j;
			}
		}
		if (max != i)
		{
            T temp = arr[][max];
            arr[][max] = arr[][i];
            arr[][i] = temp;
		}
	}
}