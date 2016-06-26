load data
--infile 'u.item'
INTO TABLE movies
APPEND
FIELDS TERMINATED BY '|'
(MOVIEID,
TITLE,
RELEASE_DATE "to_date(:RELEASE_DATE, 'dd-mon-yyyy','nls_date_language=english')",
VID_RELEASE_DATE "to_date(:VID_RELEASE_DATE, 'dd-mon-yyyy','nls_date_language=english')",  
IMDB_URL,
UNKNOWN,
ACTION,
ADVENTURE,
ANIMATION,
CHILDREN,
COMEDY,
CRIME,
DOCUMENTARY,
DRAMA,
FANTASY,
FILMNOIR, 
HORROR,
MUSICAL,
MYSTERY,
ROMANCE,
SCIFI,
THRILLER, 
WAR,
WESTERN )
 