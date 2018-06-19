git add .
git status
read -p "Are you sure? " -n 1 -r
if [[ $REPLY =~ ^[Yy]$ ]]
then
	git commit -m "fix mistakes"
	git push
fi

