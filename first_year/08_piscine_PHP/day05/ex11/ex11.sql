SELECT UPPER(`last_name`) AS 'NAME', `first_name`, `price`
FROM `member`
INNER JOIN `user_card` ON `member`.`id_user_card` = `user_card`.`id_user`
INNER JOIN `subscription` ON `member`.`id_sub` = `subscription`.`id_sub`
WHERE `subscription`.`price` > '42'
ORDER BY `user_card`.`last_name` ASC, `user_card`.`first_name` ASC 
