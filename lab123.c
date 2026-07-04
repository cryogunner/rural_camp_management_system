#include <stdio.h>
#include<string.h>
#define MAX 20 
int main()
{
    int choice;
    int participantCount = 0;
    int campDays = 0;

    int age[MAX];
    float fee[MAX];

    do
    {
        printf("\n RURAL CAMP MANAGEMENT SYSTEM");
        printf("\n1. Register Participants");
        printf("\n2. Calculate Camp Fee");
        printf("\n3. Check Discount Eligibility");
        printf("\n4. Display Statistics");
        printf("\n5. Utilities");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
			{
			    int n, i;

			    printf("\nHow many participants to register? ");
			    scanf("%d", &n);
 
			    if(n <= 0)
			    {
			        printf("Invalid number of participants.\n");
			        break;
			    }

			    for(i = 0; i < n; i++)
			    {

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
			            continue; 	
			        }
			        participantCount++;
			    }	
			    printf("\nRegistration completed.\n");
			    break;
			}
		     case 2:
		{
		    float registrationFee;
		    float foodCharge;
		    float accommodationCharge;
		
		    float totalCost;
		    float discountAmount;
		    float taxAmount;
		    float finalCost;
		
		    printf("\nEnter Camp Duration (Days): ");
		    scanf("%d", &campDays);
		
		    printf("Enter Registration Fee per Participant: ");
		    scanf("%f", &registrationFee);
		
		    printf("Enter Food Charge per Day: ");
		    scanf("%f", &foodCharge);
		
		    printf("Enter Accommodation Charge per Day: ");
		    scanf("%f", &accommodationCharge);
		
		    totalCost =
		    (registrationFee +
		     foodCharge * campDays +
		     accommodationCharge * campDays)
		     * participantCount;
		
		    if(participantCount >= 5)
		        discountAmount = totalCost * 0.10;
		    else
		        discountAmount = 0;
		
		    taxAmount = (totalCost - discountAmount) * 0.05;
		
		    finalCost = totalCost - discountAmount + taxAmount;
		
		    printf("\n===== Fee Report =====");
		    printf("\nParticipants : %d", participantCount);
		    printf("\nTotal Cost : %.2f", totalCost);
		    printf("\nDiscount : %.2f", discountAmount);
		    printf("\nTax : %.2f", taxAmount);
		    printf("\nFinal Cost : %.2f", finalCost);
		
		    break;
		}
            case 3:
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

				if(participantCount == 0)
				{
				    printf("\nNo participants registered.\n");
				    break;
				}
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

                if(participantCount > 10)
                {
                    printf("\nLarge Camp");
                }
                else
                {
                    printf("\nSmall Camp");
                }

                printf("\nCamp Status: %s",
                       participantCount >= 5 ?
                       "Active" : "Insufficient Participants");

                printf("\nMemory allocated for age array = %lu bytes",
                       sizeof(age));
                break;
            }
            case 5:
			{
                int subChoice;

			    do
			    {
			        char str1[100], str2[100];
			        int i;
			
			        printf("\n\n===== STRING & MATH UTILITIES =====");
			
			        printf("\n\nSTRING FUNCTIONS");
			        printf("\n1. Participant Name Length");
			        printf("\n2. Copy Camp Name");
			        printf("\n3. Combine Village and District");
			        printf("\n4. Compare Participant Names");
			        printf("\n5. Reverse Participant Name");
			        printf("\n6. Convert Camp Name to Uppercase");
			        printf("\n7. Convert Location to Lowercase");
			        printf("\n8. Check Palindrome Name");
			
			        printf("\n\nMATH FUNCTIONS");
			        printf("\n9. Calculate Total Camp Fee");
			        printf("\n10. Calculate Average Fee");
			        printf("\n11. Calculate Discount");
			        printf("\n12. Calculate Remaining Seats");
			        printf("\n13. Calculate Camp Revenue");
			        printf("\n14. Check Prime Participant ID");
			        printf("\n15. Factorial Utility");
			
			        printf("\n16. Back to Main Menu");
			
			        printf("\nEnter Choice: ");
			        scanf("%d",&subChoice);
			
			        switch(subChoice)
			        {
			            case 1:
			                printf("Enter Participant Name: ");
			                scanf("%s",str1);
			
			                printf("Length = %lu\n",strlen(str1));
			                break;
			
			            case 2:
			                printf("Enter Camp Name: ");
			                scanf("%s",str1);
			
			                strcpy(str2,str1);
			
			                printf("Copied Camp Name = %s\n",str2);
			                break;
			
			            case 3:
			                printf("Enter Village Name: ");
			                scanf("%s",str1);
			
			                printf("Enter District Name: ");
			                scanf("%s",str2);
			
			                strcat(str1,"-");
			                strcat(str1,str2);
			
			                printf("Full Location = %s\n",str1);
			                break;
			
			            case 4:
			                printf("Enter First Participant Name: ");
			                scanf("%s",str1);
			
			                printf("Enter Second Participant Name: ");
			                scanf("%s",str2);
			
			                if(strcmp(str1,str2)==0)
			                    printf("Names Match\n");
			                else
			                    printf("Names Do Not Match\n");
			
			                break;
			
			            case 5:
			            {
			                printf("Enter Participant Name: ");
			                scanf("%s",str1);
			
			                printf("Reverse Name = ");
			
			                for(i=strlen(str1)-1;i>=0;i--)
			                    printf("%c",str1[i]);
			
			                printf("\n");
			                break;
			            }
			
			            case 6:
			            {
			                printf("Enter Camp Name: ");
			                scanf("%s",str1);
			
			                for(i=0;str1[i]!='\0';i++)
			                {
			                    if(str1[i]>='a' && str1[i]<='z')
			                        str1[i]-=32;
			                }
			
			                printf("Uppercase Camp Name = %s\n",str1);
			                break;
			            }
			
			            case 7:
			            {
			                printf("Enter Location: ");
			                scanf("%s",str1);
			
			                for(i=0;str1[i]!='\0';i++)
			                {
			                    if(str1[i]>='A' && str1[i]<='Z')
			                        str1[i]+=32;
			                }
			
			                printf("Lowercase Location = %s\n",str1);
			                break;
			            }
			
			            case 8:
			            {
			                int flag=1;
			
			                printf("Enter Participant Name: ");
			                scanf("%s",str1);
			
			                int len=strlen(str1);
			
			                for(i=0;i<len/2;i++)
			                {
			                    if(str1[i]!=str1[len-i-1])
			                    {
			                        flag=0;
			                        break;
			                    }
			                }
			
			                if(flag)
			                    printf("Palindrome Name\n");
			                else
			                    printf("Not Palindrome\n");
			
			                break;
			            }
			
			            case 9:
			            {
			                int participants;
			                float feePerDay;
			                int days;
			
			                printf("Participants: ");
			                scanf("%d",&participants);
			
			                printf("Days: ");
			                scanf("%d",&days);
			
			                printf("Fee Per Day: ");
			                scanf("%f",&feePerDay);
			
			                printf("Total Fee = %.2f\n",
			                       participants*days*feePerDay);
			
			                break;
			            }
			
			            case 10:
			            {
			                float totalFee;
			
			                printf("Enter Total Fee: ");
			                scanf("%f",&totalFee);
			
			                if(participantCount>0)
			                    printf("Average Fee = %.2f\n",
			                           totalFee/participantCount);
			                else
			                    printf("No Participants Registered\n");
			
			                break;
			            }
			
			            case 11:
			            {
			                float amount,discount;
			
			                printf("Enter Amount: ");
			                scanf("%f",&amount);
			
			                printf("Enter Discount Percentage: ");
			                scanf("%f",&discount);
			
			                printf("Discount Amount = %.2f\n",
			                       amount*discount/100);
			
			                break;
			            }
			
			            case 12:
			            {
			                printf("Remaining Seats = %d\n",
			                       MAX-participantCount);
			                break;
			            }
			
			            case 13:
			            {
			                float revenue,expenses;
			
			                printf("Enter Revenue: ");
			                scanf("%f",&revenue);
			
			                printf("Enter Expenses: ");
			                scanf("%f",&expenses);
			
			                printf("Net Revenue = %.2f\n",
			                       revenue-expenses);
			
			                break;
			            }
			
			            case 14:
			            {
			                int id,prime=1;
			
			                printf("Enter Participant ID: ");
			                scanf("%d",&id);
			
			                if(id<2)
			                    prime=0;
			
			                for(i=2;i*i<=id;i++)
			                {
			                    if(id%i==0)
			                    {
			                        prime=0;
			                        break;
			                    }
			                }
			
			                if(prime)
			                    printf("Prime Participant ID\n");
			                else
			                    printf("Not Prime Participant ID\n");
			
			                break;
			            }
			
			            case 15:
			            {
			                int n,fact=1;
			
			                printf("Enter Number: ");
			                scanf("%d",&n);
			
			                for(i=1;i<=n;i++)
			                    fact*=i;
			
			                printf("Factorial = %d\n",fact);
			                break;
			            }
			
			            case 16:
			                printf("Returning to Main Menu...\n");
			                break;
			
			            default:
			                printf("Invalid Choice\n");
			        }
			
			    } while(subChoice != 16);
			
			    break;
				
			}
            case 6:
                printf("\nExiting Program...\n");
                break;
            default:
                printf("\nInvalid Choice!\n");
        }
    } while(choice != 6);    
    return 0;
}
