#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

class Photo {
public:
	string photoName;
	Photo(string data) {
		this->photoName = data;
	}
	~Photo() {
		
	}
};

int album, photo;
class Album {
public:
	string albumName;
	Album* parent;
	vector<Album*> childrenAlbums;//현재 앨범의 하위 디렉토리 리스트
	vector<Photo*> photos;//현재 앨범에 들어있는 사진들 리스트
	Album(string data) {
		this->albumName = data;
		parent = NULL;
	}
	~Album() {
	}
	void insertChild(Album* chi) {
		this->childrenAlbums.push_back(chi);
		return;
	}
	void insertPhoto(Photo* chi) {
		this->photos.push_back(chi);
		return;
	}
	pair<int, int> deleteChild(Album* chi) {
		int albums = 0, photos = 0;
		pair<int, int>ret;
		for (int i = 0; i < this->childrenAlbums.size(); i++) {
			if (this->childrenAlbums[i] == chi) {

				this->childrenAlbums.erase(this->childrenAlbums.begin() + i);
				break;
			}
		}
		return { albums, photos };
	}
	void DFS(Album *chi) {
		if (chi->childrenAlbums.size() == 0) {
			return;
		}
		while (chi->childrenAlbums.size() != 0) {
			for (int i = 0; i < chi->childrenAlbums.size(); i++) {
				if (chi->childrenAlbums[i]->childrenAlbums.size() != 0)
					DFS(chi->childrenAlbums[i]);
				album++;
				photo += chi->childrenAlbums[i]->photos.size();
			}
		}
		return;
	}
	void deletePhoto(Photo* chi) {
		for (int i = 0; i < this->photos.size(); i++) {
			if (this->photos[i] == chi) {
				this->photos.erase(this->photos.begin() + i);
				break;
			}
		}
		return;
	}
	void deleteAllAlbums() {
		for (int i = 0; i < this->childrenAlbums.size(); i++) {
			this->childrenAlbums.erase(this->childrenAlbums.begin() + i);
		}
		return;
	}
	void deleteAllPhotos() {
		for (int i = 0; i < this->photos.size(); i++) {
			this->photos.erase(this->photos.begin() + i);
		}
		return;
	}
	Album* searchAlbum(string data) {
		for (int i = 0; i < this->childrenAlbums.size(); i++) {//트리에 들어있는 모든 노드리스트를 순회하며 찾는다
			if (this->childrenAlbums[i]->albumName == data)
				return this->childrenAlbums[i];
		}
		return NULL;//못찾은 경우 null 리턴
	}

	Photo* searchPhotos(string data) {
		for (int i = 0; i < this->photos.size(); i++) {//트리에 들어있는 모든 노드리스트를 순회하며 찾는다
			if (this->photos[i]->photoName == data)
				return this->photos[i];
		}
		return NULL;//못찾은 경우 null 리턴
	}

	vector<Album*> returnChildren() {
		return this->childrenAlbums;
	}
	bool isExternal() {
		if (this->childrenAlbums.size() == 0)
			return true;
		else
			return false;
	}
};


class FileSystem {
private:
	Album* root;
	vector<Album*> node_list;//이 트리에 들어있는 모든 앨범들
public:
	FileSystem() {
		root = NULL;
	}
	FileSystem(string data) {
		root = new Album(data);
		node_list.push_back(root);
	}
	~FileSystem() {
	}
	void insertChild(string X, string Y) {
		Album* newAlbum = new Album(Y);
		if (X == "album") {//루트노드인 경우
			this->root->insertChild(newAlbum);
			newAlbum->parent = this->root;
		}
		else {
			Album* par = searchAlbum(X);
			if (par == NULL)//트리에 없는 노드면 리턴
				cout << -1 << endl;
			else {
				par->insertChild(newAlbum);
				newAlbum->parent = par;
			}
		}
		this->node_list.push_back(newAlbum);
	}
	void deleteChild(Album* chi) {
		for (int i = 0; i < this->node_list.size(); i++) {
			if (this->node_list[i] == chi) {
				this->node_list.erase(this->node_list.begin() + i);
				break;
			}
		}
		return;
	}
	Album* searchAlbum(string data) {
		for (int i = 0; i < this->node_list.size(); i++) {//트리에 들어있는 모든 노드리스트를 순회하며 찾는다
			if (this->node_list[i]->albumName == data)
				return this->node_list[i];
		}
		return NULL;//못찾은 경우 null 리턴
	}

	Album* returnRoot() {
		return this->root;
	}
};

bool albumAscending(Album* a, Album* b) {
	return a->albumName < b->albumName;
}

bool albumDescending(Album* a, Album* b) {
	return a->albumName > b->albumName;
}

bool photoAscending(Photo* a, Photo* b) {
	return a->photoName < b->photoName;
}

bool photoDescending(Photo* a, Photo* b) {
	return a->photoName > b->photoName;
}


int main() {
	ios::sync_with_stdio(false);
	int N;
	string cmd, input;
	//기본적으로 "album"앨범이 존재하며 이는 삭제불가
	FileSystem fileSystem("album");
	//현재 앨범위치를 나타낼 currentAlbum
	Album* currentAlbum = fileSystem.returnRoot();
	vector<Album*> sortedAlbums;
	vector<Photo*> sortedPhotos;
	cin >> N;
	while (N--) {
		album = 0, photo = 0;
		sortedAlbums.clear();
		sortedPhotos.clear();
		cin >> cmd;
		if (cmd == "mkalb") {
			cin >> input;
			if (currentAlbum->searchAlbum(input) == NULL) {
				fileSystem.insertChild(currentAlbum->albumName, input);
			}
			else {
				cout << "duplicated album name\n";
			}
		}
		else if (cmd == "rmalb") {
			pair<int, int> ret;
			cin >> input;
			Album *tempAlbum = currentAlbum->searchAlbum(input);
			if (input == "-1") {
				//현재 앨범에 속해있는 앨범이 존재한다면, 
				if (currentAlbum->childrenAlbums.size() != 0) {
					for (int i = 0; i < currentAlbum->childrenAlbums.size(); i++) {
						sortedAlbums.push_back(currentAlbum->childrenAlbums[i]);
					}
					sort(sortedAlbums.begin(), sortedAlbums.end(), albumAscending);

					//이름순으로 가장 빠른 앨범을 삭제 합니다.
					
					currentAlbum->DFS(sortedAlbums[0]);
				}
			}
			else if (input == "0") {
				//현재 앨범에 속해있는 모든 앨범을 삭제 합니다.
				for (int i = 0; i < currentAlbum->childrenAlbums.size(); i++) {
				}
			}
			else if (input == "1") {
				//현재 앨범에 속해있는 앨범이 존재한다면, 
				if (currentAlbum->childrenAlbums.size() != 0) {
					for (int i = 0; i < currentAlbum->childrenAlbums.size(); i++) {
						sortedAlbums.push_back(currentAlbum->childrenAlbums[i]);
					}
					sort(sortedAlbums.begin(), sortedAlbums.end(), albumDescending);
					//이름순으로 가장 늦은 앨범을 삭제 합니다. 
				}
			}
			else {
				//현재 앨범에 속해있는 앨범 중  input의 이름을 가진 앨범이 존재한다면,
				if (tempAlbum != NULL) {
					//해당 앨범을 삭제합니다.
				}
			}
			cout << album << " " << photo << '\n';
		}
		else if (cmd == "insert") {
			cin >> input;
			Photo* newPhoto = new Photo(input);
			if(currentAlbum->searchPhotos(input) == NULL)
				currentAlbum->insertPhoto(newPhoto);
			else {
				cout << "duplicated photo name\n";
			}
		}
		else if (cmd == "delete") {
			int deletedPhotos = 1;
			cin >> input;
			Photo* tempPhoto = currentAlbum->searchPhotos(input);
			if (input == "-1") {
				//현재 앨범에 속해있는 사진이 존재한다면,
				if (currentAlbum->photos.size() != 0) {
					for (int i = 0; i < currentAlbum->photos.size(); i++) {
						sortedPhotos.push_back(currentAlbum->photos[i]);
					}
					sort(sortedPhotos.begin(), sortedPhotos.end(), photoAscending);
					//이름순으로 가장 빠른 사진을 삭제 합니다.
					currentAlbum->deletePhoto(sortedPhotos[0]);
				}
			}
			else if (input == "0") {
				//현재 앨범에 속해있는 모든 사진을 삭제 합니다.
				deletedPhotos = currentAlbum->photos.size();
				currentAlbum->deleteAllPhotos();
			}
			else if (input == "1") {
				//현재 앨범에 속해있는 사진이 존재한다면, 
				if (currentAlbum->photos.size() != 0) {
					for (int i = 0; i < currentAlbum->childrenAlbums.size(); i++) {
						sortedPhotos.push_back(currentAlbum->photos[i]);
					}
					sort(sortedPhotos.begin(), sortedPhotos.end(), photoDescending);
					//이름순으로 가장 늦은 사진을 삭제 합니다. 
					currentAlbum->deletePhoto(sortedPhotos[0]);
				}
			}
			else {
				//현재 앨범에 속해있는 사진 중  input의 이름을 가진 사진이 존재한다면,
				if (tempPhoto != NULL) {
					//해당 사진을 삭제합니다.
					currentAlbum->deletePhoto(tempPhoto);
				}
			}
			cout << deletedPhotos << '\n';
		}
		else if (cmd == "ca") {
			cin >> input;
			Album* changeAlbum = currentAlbum->searchAlbum(input);
			if (input == "..") {
				if (currentAlbum != fileSystem.returnRoot()) {
					currentAlbum = currentAlbum->parent;
				}
			}
			else if (input == "/") {
				currentAlbum = fileSystem.returnRoot();
			}
			else {
				//현재 앨범에 속해있는 앨범 중  input의 이름을 가진 앨범으로 이동합니다.
				if(changeAlbum != NULL)
					currentAlbum = changeAlbum;
				
			}
			cout << currentAlbum->albumName << '\n';
		}
	}
	return 0;
}