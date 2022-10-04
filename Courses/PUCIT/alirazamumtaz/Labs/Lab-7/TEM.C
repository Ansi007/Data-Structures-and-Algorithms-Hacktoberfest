    #include <stdio.h>
    
    int main ()
    {
        
        int choice;
        int pos_count = 0;
        int neg_count = 0;
    
        printf ("User Entered => ");
        scanf ("%d", &choice);
        while (choice != 0)
        {
            if (choice > 0) {
                pos_count++;
            }
            else if(choice < 0){
                            neg_count++;
            }
    
            printf ("User Entered => ");
            scanf ("%d", &choice);
        }
    
        printf ("Positive Count = %d Negative Count = %d\n", pos_count, neg_count);//
    
        return 0;
    }