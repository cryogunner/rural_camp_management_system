#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    int choice;
    char pet1[100], pet2[100], temp[100];
    int i;

    do
    {
        printf("\n====================================");
        printf("\n         PET ANALYZER");
        printf("\n====================================");
        printf("\nSTRING OPERATIONS");
        printf("\n1. Find Pet Name Length");
        printf("\n2. Compare Two Pet Names");
        printf("\n3. Reverse Pet Name");
        printf("\n4. Count Vowels in Pet Name");
        printf("\n5. Convert Pet Name to Uppercase");
        printf("\n6. Convert Pet Name to Lowercase");
        printf("\n7. Generate Pet Nickname");

        printf("\n\nMATH OPERATIONS");
        printf("\n8. Calculate Daily Food Requirement");
        printf("\n9. Calculate Pet BMI");
        printf("\n10. Convert Pet Age to Human Years");
        printf("\n11. Calculate Growth Percentage");
        printf("\n12. Compare Maximum Weight");
        printf("\n13. Calculate Health Score");
        printf("\n14. Calculate Activity Score");
        printf("\n15. Calculate Activity Power Index");

        printf("\n\n0. Exit");
        printf("\n====================================");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
                printf("Enter Pet Name: ");
                fgets(pet1, sizeof(pet1), stdin);
                pet1[strcspn(pet1, "\n")] = '\0';

                printf("Length of '%s' = %lu\n",
                       pet1, strlen(pet1));
                break;

            case 2:
                printf("Enter First Pet Name: ");
                fgets(pet1, sizeof(pet1), stdin);
                pet1[strcspn(pet1, "\n")] = '\0';

                printf("Enter Second Pet Name: ");
                fgets(pet2, sizeof(pet2), stdin);
                pet2[strcspn(pet2, "\n")] = '\0';

                if(strcmp(pet1, pet2) == 0)
                    printf("Both pet names are identical.\n");
                else
                    printf("Pet names are different.\n");
                break;

            case 3:
                printf("Enter Pet Name: ");
                fgets(pet1, sizeof(pet1), stdin);
                pet1[strcspn(pet1, "\n")] = '\0';

                printf("Reversed Name: ");
                for(i = strlen(pet1) - 1; i >= 0; i--)
                    printf("%c", pet1[i]);

                printf("\n");
                break;

            case 4:
            {
                int vowels = 0;

                printf("Enter Pet Name: ");
                fgets(pet1, sizeof(pet1), stdin);
                pet1[strcspn(pet1, "\n")] = '\0';

                for(i = 0; pet1[i] != '\0'; i++)
                {
                    char ch = tolower(pet1[i]);

                    if(ch=='a'||ch=='e'||ch=='i'||
                       ch=='o'||ch=='u')
                        vowels++;
                }

                printf("Number of vowels = %d\n", vowels);
                break;
            }

            case 5:
                printf("Enter Pet Name: ");
                fgets(pet1, sizeof(pet1), stdin);
                pet1[strcspn(pet1, "\n")] = '\0';

                for(i = 0; pet1[i] != '\0'; i++)
                    pet1[i] = toupper(pet1[i]);

                printf("Uppercase Name: %s\n", pet1);
                break;

            case 6:
                printf("Enter Pet Name: ");
                fgets(pet1, sizeof(pet1), stdin);
                pet1[strcspn(pet1, "\n")] = '\0';

                for(i = 0; pet1[i] != '\0'; i++)
                    pet1[i] = tolower(pet1[i]);

                printf("Lowercase Name: %s\n", pet1);
                break;

            case 7:
                printf("Enter Pet Name: ");
                fgets(pet1, sizeof(pet1), stdin);
                pet1[strcspn(pet1, "\n")] = '\0';

                strncpy(temp, pet1, 3);
                temp[3] = '\0';
                strcat(temp, "-Buddy");

                printf("Generated Nickname: %s\n", temp);
                break;

            case 8:
            {
                float weight, food;

                printf("Enter Pet Weight (kg): ");
                scanf("%f", &weight);

                food = weight * 30;

                printf("Daily Food Requirement = %.2f grams/day\n",
                       food);
                break;
            }

            case 9:
            {
                float weight, height, bmi;

                printf("Enter Weight (kg): ");
                scanf("%f", &weight);

                printf("Enter Height (m): ");
                scanf("%f", &height);

                bmi = weight / (height * height);

                printf("Pet BMI = %.2f\n", bmi);
                break;
            }

            case 10:
            {
                int petAge;

                printf("Enter Pet Age (years): ");
                scanf("%d", &petAge);

                printf("Equivalent Human Age = %d years\n",
                       petAge * 7);
                break;
            }

            case 11:
            {
                float oldWeight, currentWeight, growth;

                printf("Enter Old Weight (kg): ");
                scanf("%f", &oldWeight);

                printf("Enter Current Weight (kg): ");
                scanf("%f", &currentWeight);

                growth = ((currentWeight - oldWeight)
                         / oldWeight) * 100;

                printf("Growth Percentage = %.2f%%\n",
                       growth);
                break;
            }

            case 12:
            {
                float weight1, weight2;

                printf("Enter Weight of Pet 1: ");
                scanf("%f", &weight1);

                printf("Enter Weight of Pet 2: ");
                scanf("%f", &weight2);

                if(weight1 > weight2)
                    printf("Pet 1 is heavier (%.2f kg)\n",
                           weight1);
                else if(weight2 > weight1)
                    printf("Pet 2 is heavier (%.2f kg)\n",
                           weight2);
                else
                    printf("Both pets have the same weight.\n");

                break;
            }

            case 13:
            {
                float weight, activity, healthScore;

                printf("Enter Weight: ");
                scanf("%f", &weight);

                printf("Enter Activity Level: ");
                scanf("%f", &activity);

                healthScore = sqrt(weight * activity);

                printf("Health Score = %.2f\n",
                       healthScore);
                break;
            }

            case 14:
            {
                float walkMin, playMin, score;

                printf("Minutes Walked: ");
                scanf("%f", &walkMin);

                printf("Minutes Played: ");
                scanf("%f", &playMin);

                score = (walkMin + playMin) / 2;

                printf("Activity Score = %.2f\n",
                       score);
                break;
            }

            case 15:
            {
                float activityLevel, powerIndex;

                printf("Enter Activity Level: ");
                scanf("%f", &activityLevel);

                powerIndex = pow(activityLevel, 2);

                printf("Activity Power Index = %.2f\n",
                       powerIndex);
                break;
            }

            case 0:
                printf("\nThank you for using Pet Analyzer!\n");
                break;

            default:
                printf("\nInvalid Choice! Please try again.\n");
        }

    } while(choice != 0);

    return 0;
}
