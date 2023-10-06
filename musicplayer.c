#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song
{
    char title[10];
    struct song *next;
};

struct song *createsong(char *title)
{
    struct song *newsong = (struct song *)malloc(sizeof(struct song));
    strcpy(newsong->title, title);
    newsong->next = NULL;
    return newsong;
}

void displayplaylist(struct song *currentsong)
{
    struct song *start = currentsong;
    do
    {
        printf("Song : %s\n", start->next);
        start = start->next;
    } while (start != currentsong);
}

int main()
{
    int n, choice, i;
    struct song *currentsong;
    struct song *prev;

    struct song *playlist = createsong("Song 1");
    struct song *firstsong = playlist;

    printf("Enter number of songs you want to add in the playlist : ");
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        char songname[50];

        
        sprintf(songname, "Song %d", i + 1);
        playlist->next = createsong(songname);

        playlist = playlist->next;
    }

    playlist->next = firstsong;
    currentsong = playlist->next;
    printf("Now Playing : %s\n", currentsong->title);
    do
    {
        printf("Enter choice \n1.Next\t\t2.Prev\t\t3.Quit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            currentsong = currentsong->next;
            printf("Song Playing : %s\n", currentsong->title);
            break;
        case 2:
            prev = currentsong;
            while (prev->next != currentsong)
            {
                prev = prev->next;
            }
            currentsong = prev;
            printf("Song Playing : %s\n", prev->title);
            break;
        case 3:
            printf("~~~~~~Quitting Music Player~~~~~\n");
            break;
        default:
            printf("Invalid Choice!!\n\t\tTRY AGAIN--> \n");
        }
        if (choice != 3)
        {
            printf("\t\tPlaylist\n");
            displayplaylist(currentsong);
            printf("\n");
        }
    } while (choice != 3);
    return 0;
}