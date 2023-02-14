#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define WHITE 0x0f
#define SCREEN_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT) 
                                
char* video_mem = (char*)0xb8000;

void clear_screen() {
  for (int i = 0; i <SCREEN_SIZE; i++) {
    video_mem[i*2] = ' ';
  }
}

void print_char(char c, int x, int y) {
    int index = y * SCREEN_WIDTH + x;
    video_mem[index*2] = c;
    video_mem[index * 2 + 1] = WHITE;
}

void print_str(char* msg, int x, int y) {
  for (int i = 0; *(msg+i) != '\0'; i++) {
    print_char(*(msg+i), x+i, y);
  }
}

