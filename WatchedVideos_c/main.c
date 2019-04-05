
/*
Implement the count_views function. It accepts an array of pointers to the Viewer struct,
the size of the array, and the character array with the video name.
It should return the number of Viewers who have watched a Video with the name video_name.

For example,

Video videos[] = { {.name = "Soccer", .unique_views = 500},
                   {.name = "Basketball", .unique_views = 1000} };
Viewer viewer = {.username = "Dave", .watched_videos = videos,
                 .watched_videos_size = 2};
Viewer *viewers[] = { &viewer };

calling count_views(viewers, 1, "Soccer") should return 1
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Video {
    char *name;
    int unique_views;
} Video;

typedef struct Viewer {
    char *username;
    Video *watched_videos;
    int watched_videos_size;
} Viewer;

int count_views(Viewer **viewers, int viewers_size, char *video_name)
{
    int count = 0;
    for(int i=0;i<viewers_size;i++){
        for(int j=0;j<viewers[i]->watched_videos_size;j++){
            if(!(strcmp(viewers[i]->watched_videos[j].name, video_name))){
                count++;
            }
        }
    }
    return count;
}

#ifndef RunTests
int main()
{
    Video videos[] = { {.name = "Soccer", .unique_views = 500},
                       {.name = "Basketball", .unique_views = 1000} };
    Viewer viewer = {.username = "Dave", .watched_videos = videos,
                     .watched_videos_size = 2};

    Viewer *viewers[] = { &viewer };
    printf("%d", count_views(viewers, 1, "Soccer")); /* should print 1 */
}
#endif
