#include "mruby.h"

void mrb_init_io(mrb_state *mrb);
#ifndef ESP_PLATFORM
void mrb_init_file(mrb_state *mrb);
void mrb_init_file_test(mrb_state *mrb);
#endif

#define DONE mrb_gc_arena_restore(mrb, 0)

void
mrb_mruby_io_gem_init(mrb_state* mrb)
{
  mrb_init_io(mrb); DONE;
  #ifndef ESP_PLATFORM
  mrb_init_file(mrb); DONE;
  mrb_init_file_test(mrb); DONE;
  #endif
}

void
mrb_mruby_io_gem_final(mrb_state* mrb)
{
}
