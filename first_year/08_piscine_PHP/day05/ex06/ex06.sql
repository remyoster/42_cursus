SELECT `title`, `summary` 
FROM `film` 
WHERE `summary` LIKE BINARY '%Vincent%' 
ORDER BY `id_film` ASC;
