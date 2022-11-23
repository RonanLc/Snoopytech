#!/bin/bash
# cette commande permet de rediriger errreur et succès dans le fichier log spécifié
exec &>>/var/log/dump-mysql.log

# variables avec les infos pratiques
time_info=$(date +%Y-%m-%d-%H-%M-%S)
dump_access="/home/maximilien/Desktop/TD_SQL/database_dump"
dump_name="$dump_access/dump_save_$time_info.sql"
log_access="/var/log/dump-mysql.log"

# on sauvegarde la database dans un fichier dump
mysqldump -u maximilien classicmodels > $dump_name 2>> $log_access 

# on compresse au format bz2 et on supprime l'ancien fichier
bzip2 $dump_name

# on cherche maintenant à controler le nombre de sauvegarde
nb_saves=$(find -name *dump_save* | wc -l)
# echo $nb_saves # for debug purposes

if [[ $nb_saves -gt 5 ]]
then
	extra_saves=$(( $nb_saves-5 ))
	# pour chaque fichier en extra, on l'efface
	for file in $( find -name *dump_save* | sort | head -n $extra_saves)
	do 
		#echo "File found: $file" # for debug purposes
		rm $file
	done
fi


echo "End of classicmodels' attempt to save - $time_info"

exit 0



