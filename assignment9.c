#include <stdio.h>
#include <string.h>

struct RobotRecord
{
    int id;
    float depth;
    float pressure;
    float temperature;
    float battery;
    char defect[20];
};

void addRecord()
{
    struct RobotRecord r;
    FILE *fp;

    fp = fopen("underwater_log.txt", "a");

    if(fp == NULL)
    {
        printf("Error Opening File!\n");
        return;
    }

    printf("\nEnter Robot ID: ");
    scanf("%d", &r.id);

    printf("Enter Depth (m): ");
    scanf("%f", &r.depth);

    printf("Enter Water Pressure (bar): ");
    scanf("%f", &r.pressure);

    printf("Enter Temperature (C): ");
    scanf("%f", &r.temperature);

    printf("Enter Battery Percentage: ");
    scanf("%f", &r.battery);

    printf("Enter Structural Defect (None/Crack/Corrosion): ");
    scanf("%s", r.defect);

    fprintf(fp, "%d %.2f %.2f %.2f %.2f %s\n",
            r.id, r.depth, r.pressure,
            r.temperature, r.battery, r.defect);

    fclose(fp);

    printf("Record Saved Successfully!\n");
}

void viewRecords()
{
    struct RobotRecord r;
    FILE *fp;

    fp = fopen("underwater_log.txt", "r");

    if(fp == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("\n--- Robot Records ---\n");

    while(fscanf(fp,"%d %f %f %f %f %s",
          &r.id,&r.depth,&r.pressure,
          &r.temperature,&r.battery,r.defect) != EOF)
    {
        printf("\nID: %d", r.id);
        printf("\nDepth: %.2f m", r.depth);
        printf("\nPressure: %.2f bar", r.pressure);
        printf("\nTemperature: %.2f C", r.temperature);
        printf("\nBattery: %.2f %%", r.battery);
        printf("\nDefect: %s\n", r.defect);
    }

    fclose(fp);
}

void generateReport()
{
    struct 
