rem sqlldr userid=biclstr/Asdqwe123 data=u.item control=movies.ctl log=movies.log  bindsize=20000000 readsize=20000000 rows=20000000
rem sqlldr userid=biclstr/Asdqwe123 data=u.data control=ratings.ctl log=ratings.log  bindsize=20000000 readsize=20000000 rows=20000000
rem sqlldr userid=biclstr/Asdqwe123 data=u.user control=users.ctl log=users.log  bindsize=20000000 readsize=20000000 rows=20000000
sqlldr userid=biclstr/Asdqwe123 data=u.genre control=genres.ctl log=genres.log  bindsize=20000000 readsize=20000000 rows=20000000