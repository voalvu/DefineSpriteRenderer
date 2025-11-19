#include <inttypes.h>
#include <raylib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct {
  uint8_t nbits;
  int16_t xmin;
  int16_t xmax;
  int16_t ymin;
  int16_t ymax;
}Rect;

typedef struct{
  uint8_t fillStyleType;
  Color color;
 } FillStyle;


typedef struct{
  uint8_t linestyleType;
  Color color;
 } LineStyle;


#define MAX_FILLSTYLES 255
#define MAX_LINESTYLES 255

typedef struct{
  FillStyle fillStyles[MAX_FILLSTYLES];
  LineStyle lineStyles[MAX_LINESTYLES];
} ShapeWithStyle;

    typedef struct{
      int16_t cdx;
      int16_t cdy;
      int16_t adx;
      int16_t ady;
     
    }Deltas;

typedef struct {
  uint16_t til;
  uint32_t tl;
  uint16_t shapeId;
  Rect rect;
} DefineShape;
