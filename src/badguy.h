//
// Interface: badguy
//
// Description:
//
//
// Author: Tobias Glaesser <tobi.web@gmx.de> (C) 2003
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef SUPERTUX_BADGUY_H
#define SUPERTUX_BADGUY_H

#include "SDL.h"
#include "bitmask.h"
#include "type.h"
#include "timer.h"
#include "texture.h"
#include "physic.h"
#include "collision.h"

/* Enemy modes: */
#define NORMAL 0
#define FLAT 1
#define KICK 2
#define HELD 3

/* Bad guy kinds: */
enum BadGuyKind {
  BAD_BSOD,
  BAD_LAPTOP,
  BAD_MONEY
};

/* Badguy type: */
struct bad_guy_type
{
  int mode;
  DyingType dying;
  BadGuyKind kind;
  bool seen;
  int dir;
  int frame;
  base_type base;
  base_type old_base;
  timer_type timer;
  physic_type physic;
};

extern texture_type img_bsod_squished_left;
extern texture_type img_bsod_squished_right;
extern texture_type img_bsod_falling_left;
extern texture_type img_bsod_falling_right;
extern texture_type img_laptop_flat_left;
extern texture_type img_laptop_flat_right;
extern texture_type img_laptop_falling_left;
extern texture_type img_laptop_falling_right;
extern texture_type img_bsod_left[4];
extern texture_type img_bsod_right[4];
extern texture_type img_laptop_left[3];
extern texture_type img_laptop_right[3];
extern texture_type img_money_left[2];
extern texture_type img_money_right[2];

extern bitmask *bm_bsod;

void badguy_create_bitmasks();

void badguy_init(bad_guy_type* pbad, float x, float y, BadGuyKind kind);

void badguy_action(bad_guy_type* pbad);
void badguy_draw(bad_guy_type* pbad);

void badguy_action_bsod(bad_guy_type* pbad);
void badguy_action_laptop(bad_guy_type* pbad);
void badguy_action_money(bad_guy_type* pbad);

void badguy_draw_bsod(bad_guy_type* pbad);
void badguy_draw_laptop(bad_guy_type* pbad);
void badguy_draw_money(bad_guy_type* pbad);

void badguy_collision(bad_guy_type* pbad, void* p_c_object, int c_object);

#endif /*SUPERTUX_BADGUY_H*/


