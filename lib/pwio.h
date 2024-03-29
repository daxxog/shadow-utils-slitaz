extern struct passwd *__pw_dup(const struct passwd *);
extern void __pw_set_changed(void);
extern int pw_close(void);
extern const struct passwd *pw_locate(const char *);
extern int pw_lock(void);
extern int pw_name(const char *);
extern const struct passwd *pw_next(void);
extern int pw_open(int);
extern int pw_remove(const char *);
extern int pw_rewind(void);
extern int pw_unlock(void);
extern int pw_update(const struct passwd *);
extern int pw_sort(void);
