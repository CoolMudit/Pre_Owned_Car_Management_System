
void gettime()
{
  time_t currentTime;
    struct tm *localTime;

    time(&currentTime);  // Get the current time in seconds since the Epoch
    
    localTime = localtime(&currentTime);  // Convert to local time

                                         // Format and print the current date and time
   

    strftime(formattedTime,sizeof(formattedTime) , "%Y-%m-%d %H:%M:%S", localTime);

 
}
