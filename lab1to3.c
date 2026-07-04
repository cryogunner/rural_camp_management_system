#include <stdio.h>
#define MAX 20 // Maximum number of participants allowed 
int main()
{
    int choice;
    int participantCount = 0;
    int campDays = 0;
// Arrays used to store participant information 
    int age[MAX];
    float fee[MAX];
/* Main menu loop.
Keeps the Rural Camp Management System running
until the user selects Exit. */ 
    do
    {
        printf("\n RURAL CAMP MANAGEMENT SYSTEM");
        printf("\n1. Register Participants");
        printf("\n2. Calculate Camp Fee");
        printf("\n3. Check Discount Eligibility");
        printf("\n4. Display Statistics");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
/* Switch-case used to implement the
menu-driven application. */ 
        switch(choice)
        {
            case 1:
			{
			    int n, i;
/* Participant Registration Module
Collects and stores participant details. */ 
			    printf("\nHow many participants to register? ");
			    scanf("%d", &n);
// Input validation using if statement 
			    if(n <= 0)
			    {
			        printf("Invalid number of participants.\n");
			        break;
			    }
// For loop used to register multiple participants 
			    for(i = 0; i < n; i++)
			    {
// Prevent array overflow by checking capacity 
			        if(participantCount >= MAX)
			        {
			            printf("\nMaximum participants reached!\n");
			            break;
			        }
			        printf("\nParticipant %d\n", participantCount + 1);
			        printf("Enter age: ");
			        scanf("%d", &age[participantCount]);
			        if(age[participantCount] <= 0)
			        {
			            printf("Invalid age. Skipping record.\n");
			            continue; 	// Continue statement skips invalid entries 
			        }
// Increment operator updates participant count 
			        participantCount++;
			    }	
			    printf("\nRegistration completed.\n");
			    break;
			}
            case 2:
            {
                float feePerDay;
                float total = 0;
                int i;
/* Camp Fee Calculation Module
Calculates total and average camp fees. */ 
                printf("\nEnter number of camp days: ");
                scanf("%d", &campDays);
                printf("Enter fee per participant per day: ");
                scanf("%f", &feePerDay);
// For loop processes all registered participants
                for(i = 0; i < participantCount; i++)
                {
// Arithmetic operator used for fee calculation 
                    fee[i] = campDays * feePerDay;
                    total += fee[i];     // Compound assignment operator 
                }
                printf("\nTotal Camp Fee = %.2f", total);
// Ternary operator prevents division by zero 
                printf("\nAverage Fee = %.2f",
                       participantCount > 0 ?
                       total / participantCount : 0.0);
                break;
            }
            case 3:
/* Discount Eligibility Module
Determines whether participants qualify
for camp benefits or discounts. */ 
            {
                if(campDays == 0)
				{
				    printf("Please calculate camp fee first.\n");
				    break;
				}
                printf("\nDiscount Eligibility:\n");
                int i;
				if(participantCount == 0)
				{
				    printf("\nNo participants registered.\n");
				    break;
				}
                for(i = 0; i < participantCount; i++)
                {
/* Logical AND operator used to evaluate
multiple eligibility conditions */ 
                    if(age[i] >= 18 && campDays >= 3)
                    {
                        printf("Participant %d Eligible\n", i + 1);
                    }
                    else
                    {
                        printf("Participant %d Not Eligible\n", i + 1);
                    }
                }
                break;
            }
            case 4:
            {
                int adults = 0;
                int children = 0;
                int seniors = 0;
                int i;
/* Statistics Module
Generates participant demographics
and camp summary information. */ 
				if(participantCount == 0)
				{
				    printf("\nNo participants registered.\n");
				    break;
				}
/* if-else-if ladder used to classify
participants into age groups */ 
                for(i = 0; i < participantCount; i++)
                {
                    if(age[i] < 18)
                    {
                        children++;
                    }
                    else if(age[i] <= 60)
                    {
                        adults++;
                    }
                    else
                    {
                        seniors++;
                    }
                }
                printf("\nTotal Participants = %d",
                       participantCount);
                printf("\nChildren = %d", children);
                printf("\nAdults = %d", adults);
                printf("\nSeniors = %d", seniors);
// if-else statement used for camp size analysis
                if(participantCount > 10)
                {
                    printf("\nLarge Camp");
                }
                else
                {
                    printf("\nSmall Camp");
                }
// Ternary operator used to determine camp status 
                printf("\nCamp Status: %s",
                       participantCount >= 5 ?
                       "Active" : "Insufficient Participants");
// sizeof operator used to display memory usage
                printf("\nMemory allocated for age array = %lu bytes",
                       sizeof(age));
                break;
            }
            case 5:
                printf("\nExiting Program...\n");
                break;
            default: 
                printf("\nInvalid Choice!\n");
        }
    } while(choice != 5);    
    return 0;
}

