#ifndef STRUCT_DEF_H
# define STRUCT_DEF_H

/**
 * Each structure must have an entry
 * in this following enumeration.
 */
enum struct_id {
  SID_WALL,
  SID_POOL,
  SID_RESSOURCE,
};

static inline const char* struct_name(enum struct_id sid)
{
  switch (sid) {
    case SID_WALL:
      return "wall";
    case SID_POOL:
      return "pool";
    case SID_RESSOURCE:
      return "ressource";
  }

  abort();
  return NULL;
}

#endif /* !STRUCT_DEF_H */
