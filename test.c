#include <stdio.h>
#include <unistd.h>  // sleep()を定義
#include <pthread.h>

// スレッド
void* thread( void* args )
{
    int counter = 0;
    while( 1 ){
        printf( "thread : %d\n", counter );
        sleep( 1 ); // スレッド 1 秒停止
        counter++;
    }

    return NULL;
}

// メインスレッド
int main()
{
    pthread_t th;

    // スレッド作成と起動
    pthread_create( &th, NULL, thread, (void *)NULL );

    // キー入力があるまで待つ
    getchar();

    return 0;
}
