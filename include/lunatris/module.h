#ifndef MODULE_H
# define MODULE_H

enum module_id {
  MODULE_WALL,
  MODULE_POOL,
  MODULE_EVAL,
};

static inline const char* module_name(enum module_id mid)
{
  switch (mid) {
    case MODULE_WALL:
      return "wall";
    case MODULE_POOL:
      return "pool";
    case MODULE_EVAL:
      return "eval";
  }

  abort();
  return NULL;
}

#endif /* !MODULE_H */
